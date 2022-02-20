/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b_a_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:16:11 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/20 19:16:37 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	get_min_2(t_stack *a_head, t_stack *b_head)
{
	int	j;
	int	k;

	j = get_min(a_head);
	k = get_min(b_head);
	if (j < k)
		return (j);
	return (k);
}

void	swap_b_a_1(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	min;

	min = get_min_2(*a_head, *b_head);
	if (op->oa == 0 && op->ob == 1)
		while (!check_b_a (*a_head, *b_head, first, min))
			swap(a_head, b_head, 10);
	if (op->oa == 0 && op->ob == 2)
		while (!check_b_a (*a_head, *b_head, first, min))
			swap(a_head, b_head, 7);
	if (op->oa == 1 && op->ob == 0)
		while (!check_b_a (*a_head, *b_head, first, min))
			swap(a_head, b_head, 6);
	if (op->oa == 1 && op->ob == 1)
	{
		while (!check_b(*b_head, first) && !check_a(*a_head, first, min))
			swap (a_head, b_head, 11);
		if (!check_a(*a_head, first, min))
			while (!check_b_a(*a_head, *b_head, first, min))
				swap (a_head, b_head, 9);
		else
			while (!check_b_a(*a_head, *b_head, first, min))
				swap (a_head, b_head, 10);
	}
}

void	swap_i_3(t_stack **a_head, t_stack **b_head, t_stack *first, int min)
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

void	swap_i_4(t_stack **a_head, t_stack **b_head, t_stack *first, int min)
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

void	swap_b_a_2(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	i;
	int	min;

	min = get_min_2(*a_head, *b_head);
	if (op->oa == 1 && op->ob == 2)
	{
		i = check_1_2(op, 100000, *a_head, *b_head);
		if (i)
		{
			if (i == 3)
				swap_i_3(a_head, b_head, first, min);
			else if (i == 4)
				swap_i_4(a_head, b_head, first, min);
		}
		else
		{
			while (!check_a(*a_head, first, min))
				swap(a_head, b_head, 9);
			while (!check_b_a(*a_head, *b_head, first, min))
				swap (a_head, b_head, 7);
		}
	}
}
