/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:49:52 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/09 17:05:01 by mruiz-ur         ###   ########.fr       */
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
	main->philo_array->num_of_philos = main->philo_count;
	while (i < main->philo_count)
	{		
		pthread_mutex_init(&main->fork[i], NULL);
		main->philo_array[i].l_fork = &main->fork[i];
        main->philo_array[i].r_fork = &main->fork[(i + 1) % main->philo_count];
		printf("Filosofo %d: l_fork=%p, r_fork=%p\n", i, 
		(void*)main->philo_array[i].l_fork, 
		(void*)main->philo_array[i].r_fork);
		i++;
	}
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);	
}
