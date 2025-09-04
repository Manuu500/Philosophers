/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:18:37 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/04 17:39:26 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>

typedef struct philosophers
{
	int	num;
	int	is_dead;
}					t_philo;

typedef struct main
{
	t_philo *philo_array;	
}					t_main;

void	set_philosopher(t_main *main, int num_philo);
void	initialize_vars(t_main *main, char **argv);
void	*ft_calloc(size_t num, size_t size);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, unsigned int leng);

#endif