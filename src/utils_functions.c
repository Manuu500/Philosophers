/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:15:33 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/09/15 17:02:23 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	int			n;
	int			sign;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (size == 0 || num == 0)
	{
		num = 1;
		size = 1;
	}
	if ((num * size) / num != size)
		return (NULL);
	a = malloc(num * size);
	if (!a)
		return (0);
	else
	{
		while (i < (num * size))
		{
			a[i] = '\0';
			i++;
		}
	}
	return (a);
}

void	ft_bzero(void *s, unsigned int leng)
{
	unsigned int	i;
	char			*a;

	a = s;
	i = 0;
	while (i < leng)
	{
		a[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}
