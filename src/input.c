/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:41:25 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/10/13 12:39:30 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_input(char **args, int argc)
{
	int		i;
	int		j;
	long	num;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] < '0' || args[i][j] > '9') && (num > INT_MAX))
			{
				printf("Invalid argument");
				exit(1);
			}
			j++;
		}
		num = ft_atoi(args[i]);
		if (num > INT_MAX || num <= 0)
		{
			printf("Argument out of range\n");
			exit(1);
		}
		i++;
	}
}
