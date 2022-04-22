/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:31:55 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 13:31:58 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *A)
{
	int	temp;

	temp = 0;
	if (A == NULL || A->next == NULL)
		return ;
	temp = A->content;
	A->content = (A->next)->content;
	(A->next)->content = temp;
	printf("sa\n");
}

void	sb(t_stack *B)
{
	int	temp;

	B = B->start;
	temp = 0;
	if (B == NULL || B->next == NULL)
		return ;
	temp = B->content;
	B->content = (B->next)->content;
	(B->next)->content = temp;
	printf("sb\n");
}

void	ss(t_stack *A, t_stack *B)
{
	if (A == NULL || A->next == NULL)
		return ;
	if (B == NULL || B->next == NULL)
		return ;
	sa(A);
	sa(B);
	printf("ss\n");
}
