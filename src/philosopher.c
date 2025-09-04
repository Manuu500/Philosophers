/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:39:28 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/04 17:40:10 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_philosopher(t_main *main, int philo_num)
{
	t_philo philo;
	(void) main;
	int	i;
	
	if (main->philo_array)
		printf("Piolita mi pana");
	i = 0;
	while (i <= philo_num)
	{
		philo.is_dead = 0;
		philo.num = i;
		i++;
	}
}
