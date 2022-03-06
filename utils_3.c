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

int	will_stay(t_stack *a_head, t_stack *head, int i, int tmp)
{
	t_stack	*temp;
	double	first;

	first = 1000;
	temp = head;
	tmp = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (temp->content > tmp && ++i)
		{
			first = tmp;
			tmp = temp->content;
		}
		else if (i && first < temp->content && ++i)
			first = temp->content;
		temp = temp->next;
	}
	while (head != a_head)
	{
		if (a_head->content > tmp && ++i)
			tmp = a_head->content;
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
