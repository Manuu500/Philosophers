/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:05:44 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/02 18:24:45 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void philos_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);

	}
}

static void	update_last_meal_time(t_philo *philo)
{
	long long current_time;
	
	current_time = get_current_time();
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time;
	philo->meals_eaten++;
	printf("El filosofo %d ha comido %d veces\n", philo->id, philo->meals_eaten);
	pthread_mutex_unlock(philo->meal_lock);
}

void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return;
	}
	pthread_mutex_unlock(philo->dead_lock);
	printf("%llu %d is thinking\n", (get_current_time() - philo->time), philo->id);
	if(philo->num_of_philos == 1)
	{
		usleep(philo->time_to_die * 1000);
		printf("%llu %d is dead\n", (get_current_time() - philo->time), philo->id);
		return ;
	}
	philos_forks(philo);
	printf("%llu %d is eating\n", (get_current_time() - philo->time), philo->id);
	update_last_meal_time(philo);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	printf("%llu %d is sleeping\n", (get_current_time() - philo->time), philo->id);
	usleep(philo->time_to_sleep * 1000 + 500);
}
