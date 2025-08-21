/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:46:54 by frea              #+#    #+#             */
/*   Updated: 2025/08/20 16:46:56 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_digit(char *av) // non e' **Av perche voglio scorrere una sola stringa alla volta
{
    int i;

    i = 0;
    if (!av || !av[0])
        return (0);
    while (av[i])
    {
        if (av[i] < '0' || av[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_atoi(char *str)
{
    int nbr;
    int i;

    i = 0;
    nbr = 0;
    while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return (nbr); // success
}
