/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:17:47 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 17:30:26 by mruiz-ur         ###   ########.fr       */
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

void	*prueba(t_main *main)
{
	(void) main;
	pthread_mutex_lock(main->write_mutex);
	printf("Hola cada hilo de filosofo se ha creado bien\n");
	pthread_mutex_unlock(main->write_mutex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main main;
	
	if (argc < 0 || argc > 6)
		return (0);
	else
	{
		// ft_bzero(&main, sizeof(main));
		check_input(argv, argc);
		initialize_vars(&main, argv);
		initialize_threads(&main, argv);
		set_philosopher(&main, argc);
		pthread_mutex_destroy(main.write_mutex);
		// free(main.philo_array);
		// free(main.fork_array);
	}
}