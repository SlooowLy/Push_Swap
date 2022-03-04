/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:50:33 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 17:50:34 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	check_push_b(t_stack *a_head)
{
	while (a_head)
	{
		if (a_head->true == 0)
			return (1);
		a_head = a_head->next;
	}
	return (0);
}

int	push_to_b(t_stack **a_head, t_stack **b_head, int operations)
{
	while (check_push_b(*a_head))
	{
		if ((*a_head)->true == 0)
			swap(a_head, b_head, 5, operations);
		else
			swap(a_head, b_head, 6, operations);
	}
	return (operations);
}

int	get_min(t_stack	*a_head)
{
	int	tmp;

	tmp = a_head->content;
	while (a_head)
	{
		if (a_head->content < tmp)
			tmp = a_head->content;
		a_head = a_head->next;
	}
	return (tmp);
}

int	check_first_last(t_stack *a_head, int b)
{
	t_stack	*tmp;

	tmp = a_head;
	while (tmp->next)
		tmp = tmp->next;
	if (a_head->content > b && tmp->content < b)
		return (1);
	return (0);
}

int	len(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
