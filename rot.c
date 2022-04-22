/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:40:20 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:40:22 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *A)
{
	int	temp;

	if (A == NULL)
		return ;
	A = A->start;
	temp = A->content;
	while (A->next != NULL)
	{
		A->content = (A->next)->content;
		(A->next)->start = A->start;
		A = A->next;
	}
	A->content = temp;
	printf("ra\n");
}

void	rb(t_stack *B)
{
	int	temp;

	if (B == NULL)
		return ;
	B = B->start;
	temp = B->content;
	while (B->next != NULL)
	{
		B->content = (B->next)->content;
		B = B->next;
	}
	B->content = temp;
	printf("rb\n");
}

void	rr(t_stack *A, t_stack *B)
{
	if (A == NULL || B == NULL)
		return ;
	ra(A);
	rb(B);
	printf("rr\n");
}
