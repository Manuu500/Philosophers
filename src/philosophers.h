/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:18:37 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/11 16:55:43 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philosophers
{
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_times_to_eat;
	int				dead;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_main
{
	int				philo_count;
	int				dead_flag;
	t_philo 		*philo_array;
	pthread_mutex_t *fork;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t write_lock;
	pthread_t		observer;
}					t_main;

int		ft_atoi(const char *str);
void	set_philosopher(t_main *main, int num_philo);
void	initialize_vars(t_main *main, char **argv);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *s, unsigned int leng);
void	initialize_threads(t_main *main, char **argv);
void	check_input(char **args, int argc);
void	*prueba(t_main *main);
void	*observer(t_main *main);
void	initialize_all_mutex(t_main *main);
void	f_error(t_main *main);
void	safe_free(t_main *main);
void	check_philos(t_main *main);
void	*routine(t_main *main);
void	start_forks(t_main *main);

#endif