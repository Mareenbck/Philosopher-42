/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:56:41 by mbascuna          #+#    #+#             */
/*   Updated: 2022/04/07 12:08:35 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data, char **av, int ac)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_eat_min = -1;
	if (ac == 6)
		data->nb_eat_min = ft_atoi(av[5]);
	data->all_ate = 0;
	data->death = 0;
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = ft_timestamp();
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_eat = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].fork1 = 0;
		data->philo[i].fork2 = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].data = data;
		data->fork_available[i] = 1;
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->mutex_forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	if (pthread_mutex_init(&(data->check_death), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	return (0);
}
