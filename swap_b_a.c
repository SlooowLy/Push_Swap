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

int	swap_b_a_utils1(t_stack **a_head,
	t_stack **b_head, t_op *op, t_stack *first)
{
	int	min;
	int	operations;

	min = get_min_2(*a_head, *b_head);
	operations = op->operations;
	if (op->o == 0)
	{
		while (!check_b(*b_head, first) && !check_a(*a_head, first, min))
			operations = swap (a_head, b_head, 11, operations);
		if (!check_a(*a_head, first, min))
			while (!check_b_a(*a_head, *b_head, first, min))
				operations = swap (a_head, b_head, 9, operations);
		else
			while (!check_b_a(*a_head, *b_head, first, min))
				operations = swap (a_head, b_head, 10, operations);
	}
	if (op->o == 2)
	{
		while (!check_a(*a_head, first, min))
			operations = swap (a_head, b_head, 9, operations);
		while (!check_b_a(*a_head, *b_head, first, min))
			operations = swap (a_head, b_head, 7, operations);
	}
	return (operations);
}

int	swap_b_a_utils2(t_stack **a_head,
	t_stack **b_head, t_op *op, t_stack *first)
{
	int	min;
	int	operations;

	min = get_min_2(*a_head, *b_head);
	operations = op->operations;
	if (op->o == 3)
	{
		while (!check_a(*a_head, first, min))
			operations = swap (a_head, b_head, 6, operations);
		while (!check_b_a(*a_head, *b_head, first, min))
			operations = swap (a_head, b_head, 10, operations);
	}
	return (operations);
}

int	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	min;
	int	operations;

	min = get_min_2(*a_head, *b_head);
	operations = op->operations;
	if (!check_b_a(*a_head, *b_head, first, min))
	{
		if (op->o == 1)
		{
			while (!check_b(*b_head, first) && !check_a(*a_head, first, min))
				operations = swap (a_head, b_head, 8, operations);
			if (!check_a(*a_head, first, min))
				while (!check_b_a(*a_head, *b_head, first, min))
					operations = swap (a_head, b_head, 6, operations);
			else
				while (!check_b_a(*a_head, *b_head, first, min))
					operations = swap (a_head, b_head, 7, operations);
		}
		else
		{
			op->operations = operations;
			operations = swap_b_a_utils1(a_head, b_head, op, first);
			op->operations = operations;
			operations = swap_b_a_utils2(a_head, b_head, op, first);
		}
	}
	operations = swap (a_head, b_head, 4, operations);
	return (operations);
}
