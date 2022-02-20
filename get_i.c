/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:32:05 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/20 19:32:07 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	get_i_1(t_op *op, int lena, int lenb, int i)
{
	if (op->oa == 0 && op->ob == 0)
		i = 0;
	if (op->oa == 0 && op->ob == 1)
		i = (lenb - op->b) + 1;
	if (op->oa == 0 && op->ob == 2)
		i = op->b;
	if (op->oa == 1 && op->ob == 0)
		i = (lena - op->a) + 1;
	if (op->oa == 1 && op->ob == 1)
	{
		i = (lenb - op->b) + 1;
		if (i < (lena - op->a) + 1)
			i = (lena - op->a) + 1;
	}
	return (i);
}

int	get_i_2(t_op *op, int lena, int lenb, int i)
{
	int	a;
	int	b;
	int	j;
	int	k;

	if (op->oa == 1 && op->ob == 2)
	{
		a = (lena - op->a) + 1;
		b = (lenb - op->b) + 1;
		j = a;
		if (j < b)
			j = b;
		k = op->b;
		if (k < op->a)
			k = op->a;
		if (k < i)
			i = k;
		if (j < i)
			i = j;
		if (i > (lena - op->a) + 1 + op->b)
			i = (lena - op->a) + 1 + op->b;
	}
	if (op->oa == 2 && op->ob == 0)
		i = op->a;
	return (i);
}
