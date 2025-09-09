/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:06 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 17:03:46 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_vars(t_main *main, char **argv)
{
	int	philo_count;
	// int	i = 0;

	philo_count = ft_atoi(argv[1]);
	philo_count--;
	main->philo_array = malloc(sizeof(char) * philo_count);
	if (!main->philo_array)
	{
		free(main->philo_array);
		exit(1);
	}
	//DEBUG
	// while (i <= fork_count)
	// {
	// 	i++;
	// 	printf("Hay %d tenedores", i);
	// }
}

void	initialize_threads(t_main *main, char **argv)
{
	int	thread_amount;
	int	i;
	
	i = 0;
	thread_amount = ft_atoi(argv[1]);
	while (i <= thread_amount)
	{
		pthread_create(&main->philo_array[i].thread, NULL, &prueba, NULL);
		i++;
	}
}
