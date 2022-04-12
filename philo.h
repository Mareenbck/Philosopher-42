/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:38:02 by mbascuna          #+#    #+#             */
/*   Updated: 2022/04/07 13:09:12 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				left_fork;
	int				right_fork;
	int				fork1;
	int				fork2;
	pthread_t		thread_id;
	struct s_data	*data;
	long long		last_meal;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat_min;
	int					all_ate;
	int					death;
	char				fork_available[250];
	pthread_mutex_t		mutex_forks[250];
	pthread_mutex_t		meal_check;
	pthread_mutex_t		check_death;
	pthread_mutex_t		print;
	t_philo				philo[250];
	long long			start_time;
}	t_data;

/********INIT.C*********/
int				ft_init_mutex(t_data *data);
int				ft_init_philo(t_data *data);
void			ft_init_data(t_data *data, char **av, int ac);

/********EXIT.C*********/
void			ft_exit_mutex(t_data *data);
void			ft_check_die(t_data *data, t_philo *philo);
void			ft_loop_check(t_data *data, t_philo *philo);

/*******ROUTINE.C*******/
void			*routine(void *philo);
int				ft_create_threads(t_data *data);
void			ft_eat(t_philo *philo, t_data *data);

/********UTILS.C********/
void			ft_sleep(int time);
void			ft_print_action(t_data *data, int id, char *str);
int				ft_atoi(const char *str);
int				ft_is_dead(t_data *data);
long long		ft_timestamp(void);

/********CHECK.C********/
int				ft_check_args(char **av);
int				ft_check_oveflow(char *av);
int				ft_check_digit(char *av);

#endif
