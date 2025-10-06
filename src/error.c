/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:00:50 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/06 17:40:09 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_error(t_main *main)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&main->dead_lock);
	pthread_mutex_destroy(&main->meal_lock);
	pthread_mutex_destroy(&main->write_lock);
	if (main->fork)
	{
		while (i < main->philo_count)
		{
			pthread_mutex_destroy(&main->fork[i]);
			i++;
		}
		free(main->fork);
	}
	if (main->philo_array)
		free(main->philo_array);
	exit (1);
}

void	safe_free(t_main *main)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&main->dead_lock);
	pthread_mutex_destroy(&main->meal_lock);
	pthread_mutex_destroy(&main->write_lock);
	if (main->fork)
	{
		while (i < main->philo_count)
		{
			pthread_mutex_destroy(&main->fork[i]);
			i++;
		}
		free(main->fork);
	}
	if (main->philo_array)
		free(main->philo_array);
	exit(0);
}
