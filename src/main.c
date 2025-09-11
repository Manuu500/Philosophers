/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:17:47 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/11 17:00:51 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//TESTING THREADS
void	*rutina()
{
	printf("Hola esta funcionando los hilos\n");
	sleep(3);
	printf("Ya no funciona\n");
	return (0);
}

void	*observer(t_main *main)
{
	(void) main;
	printf("Se ha creado el hilo observador\n");
	return (0);
}

void	*prueba(t_main *main)
{
	pthread_mutex_lock(&main->write_lock);
	printf("Hola cada hilo de filosofo se ha creado bien\n");
	pthread_mutex_unlock(&main->write_lock);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main main;
	
	if (argc < 0 || argc > 6)
		return (0);
	else
	{
		check_input(argv, argc);
		initialize_vars(&main, argv);
		initialize_all_mutex(&main);
		// set_philosopher(&main, argc);
		initialize_threads(&main, argv);
		start_forks(&main);
		check_philos(&main);
		pthread_mutex_destroy(&main.write_lock);
		safe_free(&main);
		//DEBUG
		// int i = 0;
		// while (i < main.philo_count)
		// {
		// 	if (&main.fork[i])
		// 		printf("El tenedor %d esta guardado correctamente\n", i + 1);
		// 	i++;
		// }
	}
}