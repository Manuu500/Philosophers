/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/15 19:23:53 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *main)
{
	t_philo *philo;

	philo = (t_philo *)main;
	while (!philo->dead)
	{
		printf("El filosofo %d está pensando\n", philo->id);
		sleep(1);
		printf("El filosofo %d está comiendo\n", philo->id);
		sleep(1);
		printf("El filosofo %d está durmiendo\n", philo->id);
		sleep(1);
	}
	return (0);
}

void	*r_eat(t_main *main)
{
	pthread_mutex_lock(&main->write_lock);
	printf("El filosofo %d esta ñam ñam ñam\n", main->philo_array[0].id);
	pthread_mutex_unlock(&main->write_lock);
	return (0);
}

void	*r_sleep(t_main *main)
{
	pthread_mutex_lock(&main->write_lock);
	printf("El filosofo %d esta mimiendo\n", main->philo_array[0].id);
	pthread_mutex_unlock(&main->write_lock);
	return (0);
}

void	*r_think(t_main *main)
{
	pthread_mutex_lock(&main->write_lock);
	printf("El filosofo %d esta pensando\n", main->philo_array[0].id);
	pthread_mutex_unlock(&main->write_lock);
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