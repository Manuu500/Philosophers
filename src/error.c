/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:00:50 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 19:08:09 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_error(t_main *main)
{
	if (main->fork)
		free(main->fork);
	if (main->philo_array->write_lock)
		free(main->philo_array->write_lock);
	if (main->philo_array->dead_lock)
		free(main->philo_array->dead_lock);
	if (main->philo_array->meal_lock)
		free(main->philo_array->meal_lock);
	if (main->philo_array->r_fork)
		free(main->philo_array->r_fork);
	if (main->philo_array->l_fork)
		free(main->philo_array->l_fork);
	free(main->philo_array);
	exit (1);
}
