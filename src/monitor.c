/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:44:33 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/15 15:43:01 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	monitor_loop(t_main *data, int all_eaten, int i)
{
	pthread_mutex_lock(&data->meal_lock);
	if ((data->philo_array[i].meals_eaten < data->philo_array[i].meals_to_eat))
		all_eaten = 0;
	pthread_mutex_unlock(&data->meal_lock);
	return (all_eaten);
}

static int	check_any_philo_dead(t_main *data, int is_dead, int i)
{
	if (monitor_philos(data, i) == 1)
	{
		is_dead = 1;
		return (1);
	}
	return (0);
}

static void	check_meals_eaten(t_main *data, int all_eaten)
{
	(void) data;
	if (all_eaten)
		exit (0);
}

int	monitor_philos(t_main *data, int i)
{
	int			j;
	long long	now;

	pthread_mutex_lock(data->philo_array[i].meal_lock);
	now = get_current_time();
	if (now - data->philo_array[i].last_meal > data->philo_array[i].time_to_die)
	{
		j = 0;
		while (j < data->philo_count)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->philo_array[j].dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			j++;
		}
		printf("%llu %d is dead\n",
			(get_current_time() - data->philo_array[i].time),
			data->philo_array[i].id);
		pthread_mutex_unlock(data->philo_array[i].meal_lock);
		return (1);
	}
	pthread_mutex_unlock(data->philo_array[i].meal_lock);
	return (0);
}

void	*monitor(void *main)
{
	t_main	*data;
	int		i;
	int		is_dead;
	int		all_eaten;

	is_dead = 0;
	data = (t_main *)main;
	while (is_dead != 1)
	{
		all_eaten = 1;
		i = 0;
		while (i < data->philo_count)
		{
			all_eaten = monitor_loop(data, all_eaten, i);
			if (check_any_philo_dead(data, is_dead, i) == 1)
				return (NULL);
			i++;
		}
		if (data->args_count != 5)
			check_meals_eaten(data, all_eaten);
		micro_usleep(data->philo_array, 1);
	}
	return (NULL);
}
