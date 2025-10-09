/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:06:42 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/09 17:15:06 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	only_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%llu %d has taken a fork\n", (get_current_time() - philo->time), philo->id);
	usleep(philo->time_to_die * 1000);
	printf("%llu %d died\n", (get_current_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->l_fork);
	kill_lone_philo(philo);
}

void	free_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%llu %d is sleeping\n", (get_current_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	usleep(philo->time_to_sleep * 1000 + 500);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%llu %d is eating\n", (get_current_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->write_lock);
}