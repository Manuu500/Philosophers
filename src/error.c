/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:00:50 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/24 16:53:23 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_error(t_main *main)
{
	if (main->fork)
		free(main->fork);
	if (main->philo_array)
		free(main->philo_array);
	exit (1);
}

void	safe_free(t_main *main)
{
	if (main->fork)
		free(main->fork);
	if (main->philo_array)
		free(main->philo_array);	
}
