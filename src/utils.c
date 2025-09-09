/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:06 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 19:03:58 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	allocate_all_mutex(t_main *main, int i)
{
	main->philo_array[i].dead_lock = malloc(sizeof(pthread_mutex_t) * main->philo_count + 1);
	if (!main->philo_array[i].dead_lock)
		f_error(main);
	main->philo_array[i].meal_lock = malloc(sizeof(pthread_mutex_t) * main->philo_count + 1);
	if (!main->philo_array[i].dead_lock)
		f_error(main);
	main->philo_array[i].write_lock = malloc(sizeof(pthread_mutex_t) * main->philo_count + 1);
	if (!main->philo_array[i].dead_lock)
		f_error(main);
	main->philo_array[i].l_fork = malloc(sizeof(pthread_mutex_t) * main->philo_count + 1);
	if (!main->philo_array[i].dead_lock)
		f_error(main);
	main->philo_array[i].r_fork = malloc(sizeof(pthread_mutex_t) * main->philo_count + 1);
	if (!main->philo_array[i].r_fork)
		f_error(main);
}

void	initialize_vars(t_main *main, char **argv)
{
	int	philo_count;
	// int	i = 0;

	philo_count = ft_atoi(argv[1]);
	main->philo_array = malloc(sizeof(t_philo) * philo_count);
	if (!main->philo_array)
		exit(1);
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
	while (i < thread_amount)
	{
		pthread_create(&main->philo_array[i].thread, NULL, (void *)&prueba, main);
		pthread_join(main->philo_array[i].thread, NULL);
		i++;
		main->philo_count++;
	}
}

void	initialize_all_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philo_count)
	{
		allocate_all_mutex(main, i);
		pthread_mutex_init(main->philo_array[i].dead_lock, NULL);
		pthread_mutex_init(main->philo_array[i].meal_lock, NULL);
		pthread_mutex_init(main->philo_array[i].write_lock, NULL);
		pthread_mutex_init(main->philo_array[i].l_fork, NULL);
		pthread_mutex_init(main->philo_array[i].r_fork, NULL);	
		i++;
	}
	pthread_mutex_init(&main->write_lock, NULL);
	pthread_mutex_init(&main->dead_lock, NULL);
	pthread_mutex_init(&main->meal_lock, NULL);	
}
