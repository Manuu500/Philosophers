/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/02 18:23:42 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		philo_routine(philo);
	return (0);
}

void	*monitor(void *main)
{
    t_main	*data;
    int		i;
	int		j;
    long long	now;
	int		all_eaten;

	data = (t_main *)main;
    while (1)
    {
		all_eaten = 1;
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_lock(data->philo_array[i].meal_lock);
            now = get_current_time();
			if ((data->philo_array[i].meals_eaten < data->philo_array[i].meals_to_eat))
				all_eaten = 0;
            if (now - data->philo_array[i].last_meal > data->philo_array[i].time_to_die)
			{
				j = 0;
				while (j < data->philo_count)
				{
					data->philo_array[j].dead = 1;	
					j++;
				}
				printf("%llu %d is dead\n", (get_current_time() - data->philo_array[i].time), data->philo_array[i].id);
				exit(0);
			}
			pthread_mutex_unlock(data->philo_array[i].meal_lock);
            i++;
        }
		if (all_eaten)
		{
			j = 0;
			while (j < data->philo_count)
			{
				printf("El filosofo %d ha comido %d veces\n", data->philo_array[j].id, data->philo_array[j].meals_eaten);
				j++;
			}
			exit(0);
		}
        usleep(2000);
    }
    return (NULL);	
}
