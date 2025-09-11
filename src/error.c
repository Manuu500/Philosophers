/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:00:50 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/11 17:04:21 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_error(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philo_count)
	{
		if (main->philo_array[i].write_lock)
			free(main->philo_array[i].write_lock);
		if (main->philo_array[i].dead_lock)
			free(main->philo_array[i].dead_lock);
		if (main->philo_array[i].meal_lock)
			free(main->philo_array[i].meal_lock);
		if (main->philo_array[i].r_fork)
			free(main->philo_array[i].r_fork);
		if (main->philo_array[i].l_fork)
			free(main->philo_array[i].l_fork);
		i++;
	}
	free(main->philo_array);
	exit (1);
}

void	safe_free(t_main *main)
{
	int	i;

	i = 0;
	if (main->fork)
		free(main->fork);
	while (i < main->philo_count)
	{
		if (main->philo_array[i].write_lock)
			free(main->philo_array[i].write_lock);
		if (main->philo_array[i].dead_lock)
			free(main->philo_array[i].dead_lock);
		if (main->philo_array[i].meal_lock)
			free(main->philo_array[i].meal_lock);
		if (main->philo_array[i].r_fork)
			free(main->philo_array[i].r_fork);
		if (main->philo_array[i].l_fork)
			free(main->philo_array[i].l_fork);
		i++;	
	}
	if (main->philo_array)
		free(main->philo_array);
}
