/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:54:54 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:54:58 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_copy(t_stack *A, int count)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(stack) * count);
	i = 0;
	while (A)
	{
		stack[i] = A->content;
		A = A->next;
		i++;
	}
	return (stack);
}

void	bubble(t_stack *A)
{
	int	*copy;
	int	*order;
	int	*index;
	int	count;
	int	i;

	i = -1;
	count = count_elements(A);
	index = malloc(sizeof(index) * count);
	copy = fill_copy(A, count);
	order = fill_copy(A, count);
	sort(order, count);
	while (++i < count)
		index[i] = srch_stack(order, copy[i]);
	free(order);
	free(copy);
	non_neg_a(A, index);
}

void	sort(int *stack, int count)
{
	int	i;
	int	in_order;
	int	tmp;

	tmp = 0;
	in_order = 1;
	while (in_order)
	{
		i = 0;
		in_order = 0;
		while (i < count - 1)
		{
			if (stack[i] > stack[i + 1])
			{
				tmp = stack[i];
				stack[i] = stack[i + 1];
				stack[i + 1] = tmp;
				in_order++;
			}
			i++;
		}
	}
}

int	srch_stack(int	*copy, int num)
{
	int	i;

	i = 0;
	while (copy[i] != num)
		i++;
	return (i);
}

void	non_neg_a(t_stack *A, int *index)
{
	int	i;

	i = 0;
	A = A->start;
	while (A)
	{
		A->content = index[i];
		i++;
		A = A->next;
	}
	free(index);
}
