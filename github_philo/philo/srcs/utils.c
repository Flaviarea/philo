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
        return (1);
    if (av[0] == '+' || av[0] == '-') // rifiuta segni
        return (1);
    while (av[i])
    {
        if (av[i] < '0' || av[i] > '9')
            return (1); // errore
        i++;
    }
    return (0); // corretto
}

/*
    manca che il check per INT_MAX
*/

int ft_atoi(char *str)
{
    int nbr;
    int i;
    int sign;

    i = 0;
    nbr = 0;
    sign = 1;
    while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (nbr > (INT_MAX - (str[i] - '0')) / 10)
            return (-1); // overflow
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return (nbr * sign); // success
}
