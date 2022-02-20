/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:13:51 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/20 19:13:52 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	swap_i_3_2(t_stack **a_head, t_stack **b_head, t_stack *first, int min)
{
	while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
		swap(a_head, b_head, 11);
	if (!check_a(*a_head, first, min))
		while (!check_b_a(*a_head, *b_head, first, min))
			swap(a_head, b_head, 9);
	else
		while (!check_b_a(*a_head, *b_head, first, min))
			swap(a_head, b_head, 10);
}

void	swap_i_4_2(t_stack **a_head, t_stack **b_head, t_stack *first, int min)
{
	while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
		swap(a_head, b_head, 8);
	if (!check_a(*a_head, first, min))
		while (!check_b_a(*a_head, *b_head, first, min))
			swap(a_head, b_head, 6);
	else
		while (!check_b_a(*a_head, *b_head, first, min))
			swap(a_head, b_head, 7);
}

void	swap_b_a_3(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	i;
	int	min;

	min = get_min_2(*a_head, *b_head);
	if (op->oa == 2 && op->ob == 1)
	{
		i = check_1_2(op, 10000, *a_head, *b_head);
		if (i)
		{
			if (i == 3)
				swap_i_3_2(a_head, b_head, first, min);
			else if (i == 4)
				swap_i_4_2(a_head, b_head, first, min);
		}
		else
		{
			while (!check_b(*b_head, first))
				swap(a_head, b_head, 10);
			while (!check_a(*a_head, first, min))
				swap(a_head, b_head, 6);
		}
	}
}

void	swap_b_a_4(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	min;

	min = get_min_2(*a_head, *b_head);
	if (op->oa == 2 && op->ob == 0)
	{
		while (!check_b_a(*a_head, *b_head, first, min))
			swap(a_head, b_head, 6);
	}
	if (op->oa == 2 && op->ob == 2)
	{
		if (op->a > op->b)
		{
			while (!check_b(*b_head, first))
				swap (a_head, b_head, 8);
			while (!check_b_a(*a_head, *b_head, first, min))
				swap(a_head, b_head, 6);
		}
		else
		{
			while (!check_a(*a_head, first, min))
				swap (a_head, b_head, 8);
			while (!check_b_a(*a_head, *b_head, first, min))
				swap (a_head, b_head, 7);
		}		
	}
}

void	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	i;
	int	min;

	min = get_min_2(*a_head, *b_head);
	if (!check_b_a(*a_head, *b_head, first, min))
	{
		swap_b_a_1(a_head, b_head, first, op);
		swap_b_a_2(a_head, b_head, first, op);
		swap_b_a_3(a_head, b_head, first, op);
		swap_b_a_4(a_head, b_head, first, op);
	}
	swap (a_head, b_head, 4);
}
