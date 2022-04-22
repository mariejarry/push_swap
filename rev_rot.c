/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:44:14 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:44:17 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *A)
{
	int	last;
	int	tmp1;
	int	tmp2;

	if (A == NULL)
		return ;
	while (A->next != NULL)
		A = A->next;
	last = A->content;
	A = A->start;
	tmp1 = (A->next)->content;
	(A->next)->content = A->content;
	A = A->next;
	while (A->next != NULL)
	{
		tmp2 = (A->next)->content;
		(A->next)->content = tmp1;
		tmp1 = tmp2;
		A = A->next;
	}
	(A->start)->content = last;
	printf("rra\n");
}

void	rrb(t_stack *B)
{
	int	last;
	int	tmp1;
	int	tmp2;

	if (B == NULL)
		return ;
	while (B->next != NULL)
		B = B->next;
	last = B->content;
	B = B->start;
	tmp1 = (B->next)->content;
	(B->next)->content = B->content;
	B = B->next;
	while (B->next != NULL)
	{
		tmp2 = (B->next)->content;
		(B->next)->content = tmp1;
		tmp1 = tmp2;
		B = B->next;
	}
	(B->start)->content = last;
	printf("rrb\n");
}

void	rrr(t_stack *A, t_stack *B)
{
	if (A == NULL || B == NULL)
		return ;
	rra(A);
	rrb(B);
	printf("rrr\n");
}
