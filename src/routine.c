/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/10 18:40:18 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(t_main *main)
{
	while (main->dead_flag != 1)
	{
		
	}
}

//DEBUG
void	check_philos(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philo_count)
	{
		printf("El id del filósofo es: %d\n", main->philo_array[i].id);
		i++;		
	}
}