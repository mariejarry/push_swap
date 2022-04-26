/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:38:39 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:49:10 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_start(t_stack *A)
{
	if (!A)
		return ;
	A->start = A;
	while (A->next != NULL)
	{
		(A->next)->start = A->start;
		A = A->next;
	}
}

void	pa(t_stack **A, t_stack **B)
{	
	t_stack	*temp_b;

	if (*B == NULL)
		return ;
	temp_b = (*B)->next;
	(*B)->next = *A;
	*A = *B;
	*B = temp_b;
	set_start(*A);
	set_start(*B);
	write(1, "pa\n", 3);
}

void	pb(t_stack **A, t_stack **B)
{	
	t_stack	*temp_a;

	if (*A == NULL)
		return ;
	temp_a = (*A)->next;
	(*A)->next = *B;
	*B = *A;
	*A = temp_a;
	set_start(*A);
	set_start(*B);
	write(1, "pb\n", 3);
}
