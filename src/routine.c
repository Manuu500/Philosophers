/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/30 18:14:19 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_last_meal_time(t_philo *philo)
{
	long long current_time;
	
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
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	if (philo->id % 2 == 1)
		usleep(3000);
	while (!philo->dead)
	{
		//Think
		printf("%llu %d is thinking\n", (get_current_time() - philo->time), philo->id);
		//Take forks
		if(philo->num_of_philos == 1)
		{
			usleep(philo->time_to_die * 1000);
			printf("%llu %d ha muerto\n", (get_current_time() - philo->time), philo->id);
			return (NULL);
		}
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
		//Eat time
		printf("%llu %d is eating\n", (get_current_time() - philo->time), philo->id);
		update_last_meal_time(philo);
		usleep(philo->time_to_eat * 1000);

		//Liberate forks
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);

		//Sleep
		printf("%llu %d is sleeping\n", (get_current_time() - philo->time), philo->id);
		usleep(philo->time_to_sleep * 1000 + 500);
	}
	return (0);
}

void	*monitor(void *main)
{
    t_main	*data;
    int		i;
	int		j;
    long long	now;

	data = (t_main *)main;
    while (1)
    {
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_lock(data->philo_array[i].meal_lock);
            now = get_current_time();
            if (now - data->philo_array[i].last_meal > data->philo_array[i].time_to_die)
			{
				j =20;
				while (j < data->philo_count)
				{
					data->philo_array[j].dead = 1;	
					j++;
				}
				printf("El filósofo %d ha muerto\n", data->philo_array[i].id);
				// data->phex_unlock(data->philo_array[i].meal_lock);
				exit(0);
			}
			pthread_mutex_unlock(data->philo_array[i].meal_lock);
            i++;
        }
        usleep(2000);
    }
    return (NULL);	
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