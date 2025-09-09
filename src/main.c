/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:17:47 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 16:47:56 by mruiz-ur         ###   ########.fr       */
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

void	*prueba()
{
	printf("Hola cada hilo de filosofo se ha creado bien\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_main main;
	// pthread_t t1, t2;
	
	if (argc < 0 || argc > 6)
		return (0);
	else
	{
		// ft_bzero(&main, sizeof(main));
		check_input(argv, argc);
		initialize_vars(&main, argv);
		initialize_threads(&main, argv);
		set_philosopher(&main, argc);
		// pthread_create(&t1, NULL, &rutina, NULL);
		// pthread_create(&t2, NULL, &rutina, NULL);
		// pthread_join(t1, NULL);
		// pthread_join(t2, NULL);
		// free(main.philo_array);
		// free(main.fork_array);
	}
}