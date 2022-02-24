/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:07:05 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 18:07:06 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	get_op(int lena, int lenb, t_op *op)
{
	if (op->b == 0)
		op->ob = 0;
	if (op->a == 0)
		op->oa = 0;
	if (op->b > get_len(lenb))
		op->ob = 1;
	else if (op->b <= get_len(lenb))
		op->ob = 2;
	if (op->a > get_len(lena))
		op->oa = 1;
	else if (op->a <= get_len(lena))
		op->oa = 2;
	op->o = 0;
}

int	will_stay(t_stack *a_head, t_stack *head, int i, int tmp)
{
	t_stack	*temp;
	double	first;
	int		k;

	k = 0;
	first = 10000000;
	temp = head;
	tmp = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (temp->content > tmp)
		{
			k = 1;
			i++;
			first = tmp;
			tmp = temp->content;
		}
		else if (i && first < temp->content)
		{
			k = 1;
			i++;
			first = temp->content;
		}
		else
			k = 0;
		temp = temp->next;
	}
	while (head != a_head)
	{
		if (a_head->content > tmp)
		{
			i++;
			tmp = a_head->content;
		}
		a_head = a_head->next;
	}
	return (i);
}
int	get_max(t_stack *a_head)
{
	int	i;

	i = a_head->content;
	while (a_head)
	{
		if (i < a_head->content)
			i = a_head->content;
		a_head = a_head->next;
	}
	return (i);
}

int	check_b_a(t_stack *a_head, t_stack *b_head, t_stack *first, int min)
{
	t_stack	*tmp;

	tmp = a_head;
	if (b_head != first)
		return (0);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (first->content > tmp->content && first->content < a_head->content)
			return (1);
		else if ((first->content == min
				|| first->content < get_min (a_head))
			&& a_head->content == get_min(a_head))
			return (1);
		else if ((first->content < a_head->content
				&& a_head->content == get_min(a_head)))
			return (1);
	}
	return (0);
}

int	check_a(t_stack *a_head, t_stack *first, int min)
{
	t_stack	*tmp;

	tmp = a_head;
	while (tmp->next)
			tmp = tmp->next;
	if (first->content > tmp->content && first->content < a_head->content)
		return (1);
	else if (first->content < a_head->content
		&& a_head->content == get_min(a_head))
		return (1);
	else if (first->content > tmp->content
		&& tmp->content == get_max(a_head))
		return (1);
	return (0);
}
