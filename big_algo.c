/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:51:36 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:51:37 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_stack *A, t_stack *B)
{
	int	i;
	int	count;
	int	j;

	count = count_elements(A);
	if (count < 2)
		return ;
	i = 0;
	while (i < (8 * 4) && !check(A))
	{	
		j = 0;
		while (++j <= count)
		{
			if (((A->content >> i) & 1) == 1)
				ra(A);
			else
				pb(&A, &B);
		}
		while (B)
			pa(&A, &B);
		i++;
	}
}

int	check(t_stack *A)
{
	while (A->next != NULL)
	{
		if (A->content > (A->next)->content)
			return (0);
		A = A->next;
	}
	return (1);
}
