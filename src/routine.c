/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/18 19:13:40 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_last_meal_time(t_philo *philo)
{
	long long current_time;
	(void) philo;
	
	current_time = get_current_time();
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time;
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
}

void	*routine(void *main)
{
	t_philo *philo;

	philo = (t_philo *)main;
	if (philo->id % 2 == 1)
		usleep(1000);
	while (!philo->dead)
	{
		//Think
		printf("El filósofo %d está pensando\n", philo->id);

		//Take forks
		pthread_mutex_lock(philo->l_fork);
		printf("El filósofo %d ha cogido un tenedor\n", philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("El filósofo %d ha cogido un tenedor\n", philo->id);
		
		//Eat time
		printf("El filósofo %d está comiendo\n", philo->id);
		update_last_meal_time(philo);
		usleep(philo->time_to_eat * 1000);
		
		//Liberate forks
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);

		//Sleep
		printf("El filósofo %d está durmiendo\n", philo->id);
		usleep(philo->time_to_sleep * 1000);
	}
	return (0);
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