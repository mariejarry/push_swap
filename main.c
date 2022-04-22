/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:28:11 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 14:12:22 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	count_elements(t_stack *A)
{
	int	count;

	count = 0;
	while (A != NULL)
	{
		count++;
		A = A->next;
	}
	return (count);
}

void	send_to_algorithm(t_inter stacks)
{
	bubble(stacks.a);
	if (count_elements(stacks.a) > 5)
		sort_algorithm(stacks.a, stacks.b);
	else
		small_algorithm(stacks.a, stacks.b, count_elements(stacks.a));
}

void	done(t_inter stacks)
{
	t_stack	*tmp;

	while (stacks.a->next)
	{
		tmp = (stacks.a->next);
		free(stacks.a);
		stacks.a = tmp;
	}
	free(tmp);
}

int	parsing_check(int ac, char **av)
{
	if (parsing(ac, av) < 2)
	{
		if (!parsing(ac, av))
			write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**str;
	t_inter	stacks;

	str = NULL;
	if (ac >= 2)
	{
		if (!parsing_check(ac, av))
			return (0);
		if (ac == 2)
			str = ft_split(av[1], ' ');
		else
			str = (av + 1);
		stacks.a = allocate_stack(str);
		if (ac == 2)
			free_2d(str);
		if (count_elements(stacks.a) == 1)
		{
			free(stacks.a);
			return (0);
		}
		send_to_algorithm(stacks);
		done(stacks);
	}
	return (0);
}
