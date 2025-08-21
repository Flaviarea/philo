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
# define PHILO_MIN 0

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h> 
#include <stddef.h>

typedef struct s_simulation t_simulation;

typedef struct s_philo
{
    int index;
    long meals_counter;
    long last_meal_time;
    bool full;
    pthread_mutex_t left_fork;
    pthread_mutex_t *right_fork;
    struct s_simulation *simulation;
}   t_philo;

typedef struct s_simulation
{
    long philo_nbr;
    long time_to_die;
    long time_to_sleep;
    long time_to_eat;
    long nbr_limit_meals;
    long start_simulation;
    bool end_simulation;
    t_philo *philo;
	pthread_mutex_t	print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;
}   t_simulation;

int check_args(int ac, char **av);
int ft_atoi(char *str);
int is_digit(char *av);
int error_message(const char *message, int exit_code);

#endif