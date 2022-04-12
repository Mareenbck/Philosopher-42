/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:38:12 by mbascuna          #+#    #+#             */
/*   Updated: 2022/04/07 11:07:08 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		printf("Error : Wrong number of args\n");
	else if (!ft_check_args(av))
		printf("Error : Wrong format of args\n");
	else
	{
		ft_init_data(&data, av, ac);
		ft_init_philo(&data);
		ft_init_mutex(&data);
		ft_create_threads(&data);
	}
	return (0);
}
