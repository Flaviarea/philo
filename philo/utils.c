#include "philo.h"

/*
    exit_failure è standard ed esce 1 per failure.
*/

void error_exit(const char *error)
{
    printf("%s\n", error);
    exit(EXIT_FAILURE);
}