#include "philo.h"

void *safe_malloc(size_t bytes)
{
    void *res;
    res = malloc(bytes);
    if (res == NULL)
        error_exit("Error with malloc");
    return(res);
}

static void handle_mutex_error(int status, t_opcode opcode)
{
    if (status == 0)
        return;
    if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode || DESTROY == opcode))
        error_exit("The value specified by mutex is invalid");
    else if (EINVAL == status && INIT == opcode)
        error_exit("The value specified by attr is invalid");
    else if (EDEADLK == status)
        error_exit("A deadlock will occur");
    else if (EPERM == status)
        error_exit("The current thread does not hold a lock");
    else if (ENOMEM == status)
        error_exit("The process cannot allocate");
    else if (EBUSY == status)
        error_exit("Mutex is locked");
}

static void handle_thread_error(int status, t_opcode opcode)
{
    if (status == 0)
        return;
    if (EAGAIN == status)
        error_exit("No resources to create a thread");
    else if (EINVAL == status && (CREATE == opcode))
        error_exit("The value specified by attr is invalid");
    else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
        error_exit("The value specified by thread is not joinable")
    else if (EDEADLK == status)
        error_exit("A deadlock will occur");
    else if (EPERM == status)
        error_exit("The caller does not have appropriate permissions");
    else if (ESRCH == status)
        error_exit("No thread could be found...");
}
/*
    all the functions with pthread_mutex return 0 if they are correct
    if they are wrong they return an error_value : EINVAL; EPERM..
*/

void safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
    if (LOCK == opcode)
        handle_mutex_error(pthread_mutex_lock(mutex), opcode);
    else if (UNLOCK == opcode)
        handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
    else if (INIT == opcode)
        handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
    else if (DESTROY == opcode)
        handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
    else    
        error_exit("Wrong opcode for mutex handle");
}

void safe_thread_handle(pthread *thread, void*(*foo)(void *), void *data, t_opcode opcode)
{
    if (CREATE == opcode)
        handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
    else if (JOIN == opcode)
        handle_thread_error(pthread_join(*thread, NULL), opcode);
    else if (DETACH == opcode)
        handle_thread_error(pthread_mutex_init(*thread), opcode);
    else    
        error_exit("Wrong opcode for thread handle");
}