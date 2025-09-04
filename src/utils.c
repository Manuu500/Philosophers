/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:06 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/04 17:39:42 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_vars(t_main *main, char **argv)
{
	int	philo_count;

	philo_count = ft_atoi(argv[1]);	
	main->philo_array = malloc(sizeof(char) * philo_count);
	if (!main->philo_array)
	{
		free(main->philo_array);
		exit(1);
	}
}
