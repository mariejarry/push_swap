/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:47:29 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 14:04:36 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_algorithm(t_stack *A, t_stack *B, int count)
{
	if (count > 1 && count <= 3)
		threes_algo(A);
	else if (count > 3)
		fives_algo(A, B);
}

int	find_max(t_stack *A)
{
	int	max;
	int	max_index;
	int	index;

	max = 0;
	max_index = 0;
	index = 0;
	while (A)
	{
		if (A->content > max)
		{
			max = A->content;
			max_index = index;
		}
		A = A->next;
		index++;
	}
	return (max_index);
}

void	threes_algo(t_stack *A)
{
	if (find_max(A) == 0)
		ra(A);
	else if (find_max(A) == 1 && !check(A))
		rra(A);
	if (!check(A))
		sa(A);
}

void	fives_algo(t_stack *A, t_stack *B)
{
	int	count_a;

	count_a = count_elements(A);
	while (count_elements(B) != 2)
	{
		while (A->content > 1)
		{
			ra(A);
		}
		pb(&A, &B);
	}
	threes_algo(A);
	if (B->content < (B->next)->content)
		sb(B);
	while (count_elements(B))
	{
		pa(&A, &B);
	}
}
