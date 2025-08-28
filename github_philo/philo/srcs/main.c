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
    if (ac != 5 && ac != 6)
       return (error_message("Invalid number of arguments", 1));
    if (check_args(ac, av))
        return 1;
    return(0);
}
