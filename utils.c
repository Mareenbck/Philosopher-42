/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:58:49 by mbascuna          #+#    #+#             */
/*   Updated: 2022/04/07 11:09:02 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * neg);
}

long long	ft_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print_action(t_data *data, int id, char *str)
{
	long long	time;

	time = ft_timestamp() - data->start_time;
	pthread_mutex_lock(&(data->print));
	if (!ft_is_dead(data))
		printf("%lli %i %s\n", time, id, str);
	pthread_mutex_unlock(&(data->print));
}

void	ft_sleep(int time)
{
	long long	start;

	start = ft_timestamp();
	while (1)
	{
		if (ft_timestamp() - start >= time)
			break ;
		usleep(50);
	}
}

int	ft_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->check_death);
	if (data->death == 1)
	{
		pthread_mutex_unlock(&(data->check_death));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(data->check_death));
		return (0);
	}
}
