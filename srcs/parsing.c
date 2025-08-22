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

int check_args(int ac, char **av)
{
    if (!av[1] || is_digit(av[1]))
		return (error_message("Invalid number of philosophers", 1));
	if (ft_atoi(av[1]) < PHILO_MIN || ft_atoi(av[1]) > PHILO_MAX)
		return (error_message("Invalid number of philosophers", 1));
    if (!av[2] || !is_digit(av[2]) || ft_atoi(av[2]) <= 0)
        return (error_message("Invalid time to die", 1));
    if (!av[3] || !is_digit(av[3]) || ft_atoi(av[3]) <= 0)
        return (error_message("Invalid time to eat", 1));
    if (!av[4] || !is_digit(av[4]) || ft_atoi(av[4]) <= 0)
        return (error_message("Invalid time to sleep", 1));
    if (ac == 6)
	{
		if (!is_digit(av[5]) || ft_atoi(av[5]) < 0)
			return (error_message("Invalid number of meals", 1));
	}
    return 0;
}

/*

cleaner version?


static int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	n;

	if (!is_number(av[1]))
		return (error_message("Invalid number of philosophers", 0));
	n = ft_atoi(av[1]);
	if (n < PHILO_MIN || n > PHILO_MAX)
		return (error_message("Invalid number of philosophers", 0));

	
	if (!is_number(av[2]) || ft_atoi(av[2]) <= 0)
		return (error_message("Invalid time to die", 0));


	if (!is_number(av[3]) || ft_atoi(av[3]) <= 0)
		return (error_message("Invalid time to eat", 0));

	
	if (!is_number(av[4]) || ft_atoi(av[4]) <= 0)
		return (error_message("Invalid time to sleep", 0));

	
	if (ac == 6)
	{
		if (!is_number(av[5]) || ft_atoi(av[5]) < 0)
			return (error_message("Invalid number of meals", 0));
	}
	return (1);
}

*/