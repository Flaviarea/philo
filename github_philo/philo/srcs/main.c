/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:46:38 by frea              #+#    #+#             */
/*   Updated: 2025/08/20 16:46:39 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_sim sim; // dichiaro una struct
    t_philo philos[PHILO_MAX]; // array di filosofi
    //int num_philos = 5; // esempio

    if (ac != 5 && ac != 6)
       return (error_message("Invalid number of arguments", 1));
    if (check_args(ac, av)) // se check_args e' diverso da zero, quindi errore
        return 1;
    init_simulation(&sim, philos);
    //init_forks(sim.forks, ft_atoi(av[1]));
    //init_philos(philos, &sim, sim.forks, av);
    sim.philo[0].index = 0;
    printf("Dead flag: %d\n", sim.dead_flag);
    printf("Philosopher 0 forks: %p %p\n", sim.philo[0].left_fork, sim.philo[0].right_fork);

    return(0);
}
