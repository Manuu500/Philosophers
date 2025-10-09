/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:18:37 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/09 17:15:16 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philosophers t_philo;

typedef struct s_main
{
	int				args_count;
	int				philo_count;
	int				dead_flag;
	t_philo 		*philo_array;
	pthread_mutex_t *fork;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t write_lock;
	pthread_mutex_t	clean;
	pthread_t		observer;
}					t_main;

typedef struct s_philosophers
{
	int				meals_to_eat;
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_times_to_eat;
	int				dead;
	int				num_of_philos;
	long long		time;
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
	t_main			*main;
}					t_philo;


int		ft_atoi(const char *str);
void	set_philosopher(t_main *main, int num_philo);
void	initialize_vars(t_main *main, char **argv, int argc);
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
void	*routine(void *main);
void	start_forks(t_main *main);
char	*ft_strchr(const char *s, int c);
//ROUTINES
void	*r_think(t_main *main);
void	*r_eat(t_main *main);
void	*r_sleep(t_main *main);
//
size_t	get_current_time(void);
void	assign_forks(t_main *main);
void	*monitor(void *main);
int		philo_routine(t_philo *philo);
int		monitor_philos(t_main *data, int i);
void	end_program(t_main *main);
int		check_philo_dead(t_philo *philo);
void	only_philo_case(t_philo *philo);
void	kill_lone_philo(t_philo *philo);
void	free_forks(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	philo_eating(t_philo *philo);

#endif