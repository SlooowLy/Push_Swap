/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:34:11 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 14:34:12 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus_lib.h"

int	swap_5(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 7 || swap == 8))
	{
		tm = *b_head;
		while (tm->next)
			tm = tm->next;
		tm->next = *b_head;
		tm2 = (*b_head)->next;
		(*b_head)->next = NULL;
		*b_head = tm2;
	}
	return (swap_6(a_head, b_head, swap, operations));
}

int	swap_8(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 4))
	{
		if (a_head)
		{
			tm = *b_head;
			ft_lstadd_front(a_head, ft_lstnew(tm->content));
			tm = tm->next;
			free (*b_head);
			*b_head = tm;
		}
		else
			*a_head = ft_lstnew((*b_head)->content);
	}
	return (operations);
}

int	swap_3(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 5))
	{
		if (*b_head)
		{
			temp = (*a_head)->content;
			tm = (*a_head)->next;
			ft_lstadd_front(b_head, ft_lstnew((*a_head)->content));
			free (*a_head);
			*a_head = tm;
		}
		else
		{
			temp = (*a_head)->content;
			tm = (*a_head)->next;
			*b_head = ft_lstnew(temp);
			free (*a_head);
			*a_head = tm;
		}
	}
	return (swap_4(a_head, b_head, swap, operations));
}

int	swap_4(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	int		tue;
	t_stack	*tm;
	t_stack	*tm2;

	tm = NULL;
	tm2 = NULL;
	if (checker(swap, a_head, b_head) && (swap == 6 || swap == 8))
	{
		tm = (*a_head)->next;
		tue = (*a_head)->true;
		ft_lstadd_back(a_head, ft_lstnew((*a_head)->content));
		free (*a_head);
		while ((*a_head)->next)
			*a_head = (*a_head)->next;
		(*a_head)->true = tue;
		*a_head = tm;
	}
	return (swap_5(a_head, b_head, swap, operations));
}

int	swap(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;

	if (checker(swap, a_head, b_head) && (swap == 1 || swap == 3))
	{
		tm = *a_head;
		temp = tm->content;
		tm = tm->next;
		(*a_head)->content = tm->content;
		tm->content = temp;
	}
	return (swap_2(a_head, b_head, swap, operations));
}
