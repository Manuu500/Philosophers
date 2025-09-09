/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:41:25 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/09 18:08:11 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_input(char **args, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(args[i][0] >= '0' && args[i][0] <= '9') || args[i][0] < 0)
		{
			printf("Un argumento no es válido");
			exit(1);
		}
		i++;
	}
}