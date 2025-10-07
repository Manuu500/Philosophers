/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:06 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/07 16:52:46 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_meals_argument(t_main *main, char **argv, int argc, int i)
{
	if (argc == 6)
		main->philo_array[i].meals_to_eat = ft_atoi(argv[5]);
	else
		main->philo_array[i].meals_to_eat = 0;
}

void	initialize_vars(t_main *main, char **argv, int argc)
{
	int	philo_count;
	int	i;

	i = 0;
	philo_count = ft_atoi(argv[1]);
	main->philo_count = philo_count;
	main->philo_array = malloc(sizeof(t_philo) * philo_count);
	if (!main->philo_array)
		exit(1);
	main->args_count = argc;
	while (i < main->philo_count)
	{
		check_meals_argument(main, argv, argc, i);
		main->philo_array[i].id = i;
		main->philo_array[i].meals_eaten = 0;
		main->philo_array[i].dead = 0;
		main->philo_array[i].last_meal = get_current_time();
		main->philo_array[i].write_lock = &main->write_lock;
		main->philo_array[i].dead_lock = &main->dead_lock;
		main->philo_array[i].meal_lock = &main->meal_lock;
		main->philo_array[i].time_to_die = ft_atoi(argv[2]);
		main->philo_array[i].time_to_eat = ft_atoi(argv[3]);
		main->philo_array[i].time_to_sleep = ft_atoi(argv[4]);
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
		main->philo_array[i].time = get_current_time();
		pthread_create(&main->philo_array[i].thread, NULL, (void *)&routine, &main->philo_array[i]);
		i++;
	}
	if (main->philo_count > 1)
	{
		pthread_create(&main->observer, NULL, (void *)&monitor, main);
	}
	i = 0;
	while (i < thread_amount)
	{
		pthread_join(main->philo_array[i].thread, NULL);
		i++;
	}
	if (main->philo_count > 1)
		pthread_join(main->observer, NULL);
}

void	initialize_all_mutex(t_main *main)
{
	pthread_mutex_init(&main->write_lock, NULL);
	pthread_mutex_init(&main->dead_lock, NULL);
	pthread_mutex_init(&main->meal_lock, NULL);	
}

void	end_program(t_main *main)
{
	int	i;

	if (main->philo_array)
		free(main->philo_array);
	if (main->fork)
		free(main->fork);
	pthread_mutex_destroy(main->fork);
	pthread_mutex_destroy(&main->dead_lock);
	pthread_mutex_destroy(&main->meal_lock);
	pthread_mutex_destroy(&main->write_lock);
	i = 0;
	while(i < main->philo_count)
	{
		pthread_mutex_destroy(main->philo_array[i].r_fork);
		pthread_mutex_destroy(main->philo_array[i].l_fork);
		pthread_mutex_destroy(main->philo_array[i].write_lock);
		pthread_mutex_destroy(main->philo_array[i].dead_lock);
		pthread_mutex_destroy(main->philo_array[i].meal_lock);
		i++;
	}	
}
// void	assign_forks(t_main *main)
// {
// 	(void) main;
// 	// int	i;

// 	// i = 0;
// 	// while (i < main->philo_count)
// 	// {
// 	// 	main->philo_array[i].l_fork = &main->fork[i];
//     //     main->philo_array[i].r_fork = &main->fork[(i + 1) % main->philo_count];
// 	// 	printf("Filosofo %d: l_fork=%p, r_fork=%p\n", i, 
// 	// 	(void*)main->philo_array[i].l_fork, 
// 	// 	(void*)main->philo_array[i].r_fork);
// 	// 	i++;
// 	// }
// }
