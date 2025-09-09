/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:18:37 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 17:09:45 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct philosophers
{
	int	index;
	pthread_t thread;
}					t_philo;

typedef struct main
{
	t_philo *philo_array;
	pthread_mutex_t	*fork;
	pthread_mutex_t *write_mutex;	
}					t_main;

int		ft_atoi(const char *str);
void	set_philosopher(t_main *main, int num_philo);
void	initialize_vars(t_main *main, char **argv);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *s, unsigned int leng);
void	initialize_threads(t_main *main, char **argv);
void	check_input(char **args, int argc);
void	*prueba(t_main *main);

#endif