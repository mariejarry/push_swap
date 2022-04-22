/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:16:03 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 14:23:58 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	just_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	parsing(int ac, char **av)
{
	av++;
	if (just_space(av[0]))
		return (1);
	if (ac == 2 && !just_space(av[0]))
		av = ft_split(av[0], ' ');
	if (!ft_check_doubles(av))
	{
		if (ac == 2)
			free_2d(av);
		return (0);
	}
	if (!valid_args(av))
	{
		if (ac == 2)
			free_2d(av);
		return (0);
	}
	if (ac == 2)
		free_2d(av);
	return (2);
}

int	ft_check_doubles(char **str)
{
	int	a;
	int	b;
	int	j;

	a = 0;
	while (str[a])
	{
		b = a + 1;
		while (str[b])
		{
			j = 0;
			while (str[a][j] && str[b][j])
			{
				if (str[a][j] == str[b][j])
					j++;
				else
					break ;
			}
			if (str[a][j] == str[b][j])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	valid_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' && j == 0) &&
				(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
				j++;
			else if ((av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (0);
		}
		if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
