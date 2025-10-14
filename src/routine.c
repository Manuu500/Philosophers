/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/14 16:37:27 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philos_forks(t_philo *philo)
{
	if (check_philo_dead(philo) == 1)
		return (1);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		if (check_philo_dead(philo) == 1)
			return (1);
		printf("%llu %d has taken a fork\n", eat_time(philo), philo->id);
		pthread_mutex_lock(philo->r_fork);
		if (check_philo_dead(philo) == 1)
			return (1);
		printf("%llu %d has taken a fork\n", eat_time(philo), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		if (check_philo_dead(philo) == 1)
			return (1);
		printf("%llu %d has taken a fork\n", eat_time(philo), philo->id);
		pthread_mutex_lock(philo->l_fork);
		if (check_philo_dead(philo) == 1)
			return (1);
		printf("%llu %d has taken a fork\n", eat_time(philo), philo->id);
	}
	return (0);
}

static int	update_last_meal_time(t_philo *philo)
{
	long long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time;
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	if (check_philo_dead(philo) == 1)
		return (1);
	return (0);
}

void	kill_lone_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	philo->dead = 1;
	pthread_mutex_unlock(philo->dead_lock);
}

void	*routine(void *main)
{
	t_philo	*philo;

	philo = (t_philo *)main;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	if (philo->id % 2 == 1)
		usleep(3000);
	while (1)
	{
		if (check_philo_dead(philo) == 1)
			break ;
		philo_routine(philo);
	}
	return (0);
}

int	philo_routine(t_philo *philo)
{
	if (check_philo_dead(philo) == 1)
		return (1);
	printf("%llu %d is thinking\n",
		(get_current_time() - philo->time), philo->id);
	if (philo->num_of_philos == 1)
	{
		only_philo_case(philo);
		return (1);
	}
	philos_forks(philo);
	if (check_philo_dead(philo) == 1)
		return (1);
	philo_eating(philo);
	if (update_last_meal_time(philo) == 1)
		return (1);
	micro_usleep(philo, philo->time_to_eat);
	free_forks(philo);
	if (check_philo_dead(philo) == 1)
		return (1);
	philo_sleeping(philo);
	if (check_philo_dead(philo) == 1)
		return (1);
	return (0);
}
