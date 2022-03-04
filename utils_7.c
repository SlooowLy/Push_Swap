/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:20:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 18:20:55 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	get_len(double ln)
{
	int		i;
	int		k;
	double	j;

	k = ln / 2;
	j = ln / 2;
	if (k != j)
		return (ln / 2 + 1);
	return (ln / 2);
}

int	get_op_utils(int lena, int lenb, t_op *op, int i)
{
	if (lena - op->a > lenb - op->b)
		i = lena - op->a + 1;
	else
		i = lenb - op->b + 1;
	op->o = 0;
	if (op->a >= op->b)
	{
		if (i > op->a)
		{
			i = op->a;
			op->o = 1;
		}
	}
	else
	{
		if (i > op->b)
		{
			i = op->b;
			op->o = 1;
		}
	}
	return (i);
}

int	get_op_utils2(int lena, int lenb, t_op *op, int i)
{
	if (i > (lena - op->a) + op->b + 1)
	{
		op->o = 2;
		i = (lena - op->a) + op->b + 1;
	}
	if (i > (lenb - op->b) + op->a + 1)
	{
		op->o = 3;
		i = (lenb - op->b) + op->a + 1;
	}
	return (i);
}

int	get_op_2(int lena, int lenb, t_op *op)
{
	int	i;

	i = 0;
	i = get_op_utils(lena, lenb, op, i);
	i = get_op_utils2(lena, lenb, op, i);
	return (i);
}

void	get_default(t_25_line_2 *t, t_op *op, t_stack *a_head, t_stack *b_head)
{
	op->b = 0;
	op->a = 0;
	t->k = 1000000;
	t->lena = len(a_head);
	t->lenb = len(b_head);
}
