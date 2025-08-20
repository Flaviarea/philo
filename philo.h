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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <phtread.h>
#include <limits.h>
#include <sys/time.h> 

typedef struct s_table t_table;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_philo
{
    int index;
    long meals_counter;
    long last_meal_time;
    bool full;
    t_fork *left_fork;
    t_fork *right_fork;
    phtread_t thread_id;
    t_table *table;
}   t_philo;

typedef struct s_table
{
    long philo_nbr;
    long time_to_die;
    long time_to_sleep;
    long time_to_eat;
    long nbr_limit_meals;
    long start_simulation;
    bool end_simulation;
    t_fork *forks;
    t_fork *philos;
}   t_table;
