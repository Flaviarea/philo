/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:46:45 by frea              #+#    #+#             */
/*   Updated: 2025/08/20 16:46:47 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	In C, 0 significa “falso” e qualunque numero diverso da 0 significa “vero”.
	Quindi, quando una funzione come no_digit() ritorna 0, vuol dire “nessun errore” → falso.
	Quando ritorna 1, vuol dire “errore” → vero.
*/

int check_args(int ac, char **av)
{
    if (!av[1] || no_digit(av[1])) // se no_digit è diverso da zero
		return (error_message("Invalid number of philosophers", 1));
	if (ft_atoi(av[1]) < PHILO_MIN || ft_atoi(av[1]) > PHILO_MAX)
		return (error_message("Invalid number of philosophers", 1));
    if (!av[2] || no_digit(av[2]) || ft_atoi(av[2]) <= 0)
        return (error_message("Invalid time to die", 1));
    if (!av[3] || no_digit(av[3]) || ft_atoi(av[3]) <= 0)
        return (error_message("Invalid time to eat", 1));
    if (!av[4] || no_digit(av[4]) || ft_atoi(av[4]) <= 0)
        return (error_message("Invalid time to sleep", 1));
    if (ac == 6)
    {
        if (!av[5] || no_digit(av[5]) || ft_atoi(av[5]) < 0)
            return (error_message("Invalid number of meals", 1)); // zero è ok qui
    }
    return 0;
}