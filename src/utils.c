/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:06 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/17 18:34:55 by mruiz-ur         ###   ########.fr       */
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
	int	i;

	i = 0;
	philo_count = ft_atoi(argv[1]);
	main->philo_count = philo_count;
	main->philo_array = malloc(sizeof(t_philo) * philo_count);
	if (!main->philo_array)
		exit(1);
	while (i < main->philo_count)
	{
		main->philo_array[i].id = i;
		main->philo_array[i].meals_eaten = 0;
		main->philo_array[i].num_times_to_eat = 0;
		main->philo_array[i].dead = 0;
		main->philo_array[i].last_meal = 0;
		main->philo_array[i].time_to_die = 0;
		main->philo_array[i].write_lock = 0;
		main->philo_array[i].dead_lock = 0;
		main->philo_array[i].meal_lock = 0;
		i++;
	}
}

void	initialize_threads(t_main *main, char **argv)
{
	int	thread_amount;
	int	i;
	
	i = 0;
	thread_amount = ft_atoi(argv[1]);
	while (i < thread_amount)
	{
		pthread_create(&main->philo_array[i].thread, NULL, (void *)&routine, &main->philo_array[i]);
		i++;
	}
	pthread_join(main->philo_array[1].thread, NULL);
	if (main->philo_count > 1)
	{
		pthread_create(&main->observer, NULL, (void *)&observer, main);
		pthread_join(main->observer, NULL);	
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

void	assign_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philo_count)
	{
		main->philo_array[i].l_fork = &main->fork[i];
        main->philo_array[i].r_fork = &main->fork[(i + 1) % main->philo_count];
		    printf("Filosofo %d: l_fork=%p, r_fork=%p\n", i, 
            (void*)main->philo_array[i].l_fork, 
            (void*)main->philo_array[i].r_fork);
		i++;
	}
}
