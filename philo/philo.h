#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h> // mutex
#include <limits.h> //int max
#include <sys/time.h> //gettimofday

/*
    opcode for mutex
    Symbolic constants
*/

typedef enum e_opcode
{
    LOCK;
    UNLOCK;
    INIT;
    DESTROY;
    CREATE;
    JOIN;
    DETACH;
} t_opcode


/*
    code more readable
*/

typedef pthread_mutex_t t_mtx; //invento un soprannome -come fire- Giovanni si chiama Gio
typedef struct s_table t_table;

typedef struct s_fork 
{
    t_mtx fork;  // mutex lock/unlock
    int fork_id;
}   t_fork;

/*
    ./philo 5 800 200 200 [5]
    struct for philo
    Metti i puntatori alle forchette dentro t_philo 
    perché i filosofi hanno bisogno delle forchette, 
    ma le forchette non “appartengono” ai filosofi (sono condivise).
*/

typedef struct s_philo
{
    int id;
    long meals_counter;
    bool full;
    long last_meal_time; // time past from last meal
    t_fork *left_fork; // puntatore alla forchetta che contiene mutex + id
    t_fork *right_fork;
    pthread_t thread_id; // a philo is a thread
    t_table *table;
} t_philo;

typedef struct s_table
{
    long philo_nbr;
    long time_to_die;
    long time_to_sleep;
    long time_to_eat;
    long nbr_limit_meals; // flag 
    long start_simulation;
    bool end_simulation; // a philo dies or all philos full
    t_fork *forks; // array to forks
    t_fork *philos;
} t_table;

void parse_input(t_table *table, char **av);
void error_exit(const char *error);
void safe_thread_handle(pthread *thread, void*(*foo)(void *), void *data, t_opcode opcode);
void safe_mutex_handle(t_mtx *mutex, t_opcode opcode);

#endif