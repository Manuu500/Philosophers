/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:41:25 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/15 17:14:00 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_input(char **args, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
			{
				printf("Argumento no valido");
				exit(1);
			}
			j++;
		}
		i++;
	}
}