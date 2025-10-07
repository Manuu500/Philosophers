/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:17:47 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/07 16:53:07 by mruiz-ur         ###   ########.fr       */
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
	
	printf("Hay %d argumentos\n", argc);
	if (argc != 5 && argc != 6)
		return (0);
	else
	{
		check_input(argv, argc);
		initialize_vars(&main, argv, argc);
		initialize_all_mutex(&main);
		start_forks(&main);
		initialize_threads(&main, argv);
		end_program(&main);
	}
}
