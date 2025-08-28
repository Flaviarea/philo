/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:47:06 by frea              #+#    #+#             */
/*   Updated: 2025/08/20 16:47:08 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200
# define PHILO_MIN 1

# define VALID 0
# define INVALID -1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h> 
#include <stddef.h>

typedef struct s_simulation t_sim;

typedef struct s_philo
{
    pthread_t thread;
    int index;
    int philo_nbr;
    int eating; //
    int meals_to_eat;
    int meals_eaten;
    int *dead; // flag
    size_t last_meal; // 
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t time_to_die;
    size_t start_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t	*print_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
}   t_philo;

typedef struct s_simulation
{
    int dead_flag; // flag to set to zero at the begin of the simulation
    pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
    pthread_mutex_t forks[PHILO_MAX]; // array of forks
	t_philo *philo;
}   t_sim;

int check_args(int ac, char **av);
int ft_atoi(char *str);
int no_digit(char *av);
int error_message(const char *message, int exit_code);
void init_simulation(t_sim *sim, t_philo *philos);

#endif