/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:49:52 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/11 16:55:00 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_forks(t_main *main)
{
	int	i;

	main->fork = malloc(sizeof(pthread_mutex_t) * main->philo_count);
	if (!main->fork)
		f_error(main);
	i = 0;
	while (i < main->philo_count)
	{
		pthread_mutex_init(&main->fork[i], NULL);
		printf("Se ha creado el tenedor: %i\n", i + 1);
		i++;
	}
}