/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:59:45 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 14:24:08 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

int		parsing(int ac, char **av);
int		ft_check_doubles(char **str);
int		valid_args(char **av);

void	free_2d(char **str);

typedef struct s_stack
{
	struct s_stack	*start;
	int				content;
	struct s_stack	*next;
}				t_stack;

typedef struct s_inter
{
	t_stack		*a;
	t_stack		*b;
}				t_inter;

t_stack	*allocate_stack(char **str);

void	sa(t_stack *A);
void	sb(t_stack *B);
void	ss(t_stack *A, t_stack *B);
void	pa(t_stack **A, t_stack **B);
void	pb(t_stack **A, t_stack **B);
void	ra(t_stack *A);
void	rb(t_stack *B);
void	rr(t_stack *A, t_stack *B);
void	rra(t_stack *A);
void	rrb(t_stack *B);
void	rrr(t_stack *A, t_stack *B);

int		count_elements(t_stack *A);
void	bubble(t_stack *A);
void	sort(int *stack, int count);
int		srch_stack(int	*copy, int num);
void	non_neg_a(t_stack *A, int *index);
void	sort_algorithm(t_stack *A, t_stack *B);
int		check(t_stack *A);
void	small_algorithm(t_stack *A, t_stack *B, int count);
void	threes_algo(t_stack *A);
void	fives_algo(t_stack *A, t_stack *B);

#endif
