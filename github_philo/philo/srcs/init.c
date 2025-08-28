#include "philo.h"

void init_simulation(t_sim *sim, t_philo *philos) // *philos e' stata creata nel main
{
    int i;

    i = 0;
    sim->dead_flag = 0; // no one is dead
    sim->philo = philos; // pointing to the beginning of the array philos in the main so we dont create duplicates
    pthread_mutex_init(&sim->print_lock, NULL);
    pthread_mutex_init(&sim->meal_lock, NULL);
    pthread_mutex_init(&sim->dead_lock, NULL);
    while (i < philos->philo_nbr)
    {
        pthread_mutex_init(&sim->forks[i], NULL);
        i++;
    }
}