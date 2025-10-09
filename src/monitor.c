/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:44:33 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/09 16:13:46 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_meals_eaten(t_main *data, int all_eaten)
{
	// int	j;
	(void) data;
	if (all_eaten)
	{
		// j = 0;
		// while (j < data->philo_count)
		// {
		// 	printf("El filosofo %d ha comido %d veces\n", data->philo_array[j].id, data->philo_array[j].meals_eaten);
		// 	j++;
		// }
		exit(0);
	}
}

int	monitor_philos(t_main *data, int i)
{
	int	j;
    long long	now;

	pthread_mutex_lock(data->philo_array[i].meal_lock);
	now = get_current_time();
	if (now - data->philo_array[i].last_meal > data->philo_array[i].time_to_die)
	{
		j = 0;
		while (j < data->philo_count)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->philo_array[j].dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			j++;
		}
		printf("%llu %d is dead\n", (get_current_time() - data->philo_array[i].time), data->philo_array[i].id);
		pthread_mutex_unlock(data->philo_array[i].meal_lock);
		return(1);
	}
	pthread_mutex_unlock(data->philo_array[i].meal_lock);
	return (0);
}

void	*monitor(void *main)
{
    t_main	*data;
    int		i;
	int		is_dead = 0;
	int		all_eaten;

	data = (t_main *)main;
    while (is_dead != 1)
    {
		all_eaten = 1;
        i = 0;
        while (i < data->philo_count)
        {
			pthread_mutex_lock(&data->meal_lock);
			if ((data->philo_array[i].meals_eaten < data->philo_array[i].meals_to_eat))
				all_eaten = 0;
			pthread_mutex_unlock(&data->meal_lock);
			if (monitor_philos(data, i) == 1)
				is_dead = 1;
            i++;
        }
		if (data->args_count != 5)
			check_meals_eaten(data, all_eaten);
        usleep(2000);
    }
	printf("monitor exit\n");
    return (NULL);	
}
