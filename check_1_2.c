/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:18:19 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 18:18:20 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	check_1_2_1(t_op *op, t_stack *a_head, t_stack *b_head, int j)
{
	int	b;
	int	a;
	int	k;
	int	i;

	i = 100000;
	b = len(b_head) - op->b;
	a = len(a_head) - op->a;
	j = a;
	if (j < b)
		j = b;
	k = op->b;
	if (k < op->a)
		k = op->a;
	if (k < i)
	{
		op->o = 4;
		i = k;
	}
	if (j < i)
	{
		op->o = 3;
		i = j;
	}
	return (i);
}

int	check_1_2_2(t_op *op, t_stack *a_head, t_stack *b_head, int j)
{
	int	a;
	int	b;
	int	i;
	int	k;

	i = 1000000;
	a = len(a_head) - op->a;
	b = len(b_head) - op->b;
	j = a;
	if (j < b)
		j = b;
	k = op->b;
	if (k < op->a)
		k = op->a;
	if (k < i)
	{
		op->o = 4;
		i = k;
	}
	if (j < i)
	{
		op->o = 3;
		i = j;
	}
	return (i);
}

int	check_1_2(t_op *op, int i, t_stack *a_head, t_stack *b_head)
{
	int	j;
	int	k;
	int	a;
	int	b;

	if (op->oa == 1 && op->ob == 2)
	{
		i = check_1_2_1(op, a_head, b_head, j);
		if (i > ((len(a_head) - op->a) + 1) + op->b)
		{
			op->o = 0;
			i = ((len(a_head) - op->a) + 1) + op->b;
		}
	}
	if (op->oa == 2 && op->ob == 1)
	{
		i = check_1_2_2(op, a_head, b_head, j);
		if (i > ((len(b_head) - op->b) + 1) + op->a)
		{
			op->o = 0;
			i = ((len(b_head) - op->b) + 1) + op->a;
		}
	}
	return (op->o);
}

int	check_b(t_stack *b_head, t_stack *first)
{
	if (b_head != first)
		return (0);
	return (1);
}
