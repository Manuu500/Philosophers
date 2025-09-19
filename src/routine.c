/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:12:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/19 19:03:36 by mruiz-ur         ###   ########.fr       */
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

void	*monitor(void *main)
{
    t_main	*data = (t_main *)main;
    int		i;
    long long	now;

    while (1)
    {
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_lock(data->philo_array[i].meal_lock);
            now = get_current_time();
            if (now - data->philo_array[i].last_meal > data->philo_array[i].time_to_die)
            {
                printf("El filósofo %d ha muerto\n", data->philo_array[i].id);
                data->philo_array[i].dead = 1;
                pthread_mutex_unlock(data->philo_array[i].meal_lock);
                return (NULL); // Termina el hilo observador
            }
            pthread_mutex_unlock(data->philo_array[i].meal_lock);
            i++;
        }
        usleep(1000); // Pequeña espera para no saturar la CPU
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