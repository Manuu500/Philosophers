/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/09 16:19:51 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	kill_lone_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	philo->dead = 1;
	pthread_mutex_unlock(philo->dead_lock);
}

static int philos_forks(t_philo *philo)
{
	if (check_philo_dead(philo) == 1)
		return(1);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		if (check_philo_dead(philo) == 1)
            return(1);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
		pthread_mutex_lock(philo->r_fork);
		if (check_philo_dead(philo) == 1)
            return(1);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		if (check_philo_dead(philo) == 1)
            return(1);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
		pthread_mutex_lock(philo->l_fork);
		if (check_philo_dead(philo) == 1)
            return(1);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
	}
	return(0);
}

static int	update_last_meal_time(t_philo *philo)
{
	long long current_time;
	
	current_time = get_current_time();
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time;
	philo->meals_eaten++;
	printf("El filosofo %d ha comido %d veces\n", philo->id, philo->meals_eaten);
	pthread_mutex_unlock(philo->meal_lock);
	if (check_philo_dead(philo) == 1)
		return(1);
	return (0);
}

void	*routine(void *main)
{
	t_philo *philo;

	philo = (t_philo *)main;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	if (philo->id % 2 == 1)
		usleep(3000);
	while (1)
	{
		if (check_philo_dead(philo) == 1)
			break;
		philo_routine(philo);
	}
	printf("philo %i exit\n", philo->id);
	return (0);
}

int	philo_routine(t_philo *philo)
{
	if (check_philo_dead(philo) == 1)
		return(1);
	printf("%llu %d is thinking\n", (get_current_time() - philo->time), philo->id);
	if(philo->num_of_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
		usleep(philo->time_to_die * 1000);
		printf("%llu %d died\n", (get_current_time() - philo->time), philo->id);
		pthread_mutex_unlock(philo->l_fork);
		kill_lone_philo(philo);
		return (1);
	}
	philos_forks(philo);
	if (check_philo_dead(philo) == 1)
		return(1);
	pthread_mutex_lock(philo->write_lock);
	printf("%llu %d is eating\n", (get_current_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	if (update_last_meal_time(philo) == 1)
		return(1);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	if (check_philo_dead(philo) == 1)
		return(1);
	pthread_mutex_lock(philo->write_lock);
	printf("%llu %d is sleeping\n", (get_current_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->time_to_sleep * 1000 + 500);
	if (check_philo_dead(philo) == 1)
		return(1);
	return (0);
}

