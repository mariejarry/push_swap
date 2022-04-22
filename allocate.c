/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:30:47 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:30:56 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

t_stack	*allocate_stack(char **str)
{
	int		size;
	int		i;
	t_stack	*fill;

	fill = malloc(sizeof(t_stack));
	i = 0;
	size = word_count(str);
	fill->start = fill;
	while (i < size - 1)
	{
		fill->next = malloc(sizeof(t_stack));
		fill->content = ft_atoi(str[i]);
		(fill->next)->start = fill->start;
		fill = fill->next;
		i++;
	}
	fill->next = NULL;
	fill->content = ft_atoi(str[i]);
	fill = fill->start;
	return (fill);
}
