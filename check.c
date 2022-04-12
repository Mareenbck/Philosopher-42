/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:33:41 by mbascuna          #+#    #+#             */
/*   Updated: 2022/04/07 12:09:16 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_digit(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_oveflow(char *av)
{
	if (ft_atoi(av) > INT_MAX || ft_atoi(av) < 0)
		return (0);
	return (1);
}

int	ft_check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_check_digit(av[i]) || !ft_check_oveflow(av[i]))
			return (0);
		i++;
	}
	return (1);
}
