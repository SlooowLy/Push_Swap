/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:17:52 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 15:18:19 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus_lib.h"

int	checker_2(int swap, t_stack **a_head, t_stack **b_head)
{
	if (swap == 3 && *a_head && *b_head)
	{
		if ((*a_head)->next && (*b_head)->next)
			return (1);
		return (0);
	}
	if (swap == 4 || swap == 7 || swap == 10)
	{
		if (*b_head)
			return (1);
		return (0);
	}
	if (swap == 5 || swap == 6 || swap == 9)
	{
		if (*a_head)
			return (1);
		return (0);
	}
	if (swap == 8 || swap == 11)
	{
		if (*a_head && *b_head)
			return (1);
		return (0);
	}
	return (0);
}

int	checker(int swap, t_stack **a_head, t_stack **b_head)
{
	int	i;

	i = 0;
	if (swap == 1 && *a_head)
	{
		if ((*a_head)->next)
			return (1);
		return (0);
	}
	if (swap == 2 && *b_head)
	{
		if ((*b_head)->next)
			return (1);
		return (0);
	}
	return (checker_2(swap, a_head, b_head));
}

int	swap_7(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 10 || swap == 11))
	{
		tm = *b_head;
		tm2 = *b_head;
		while (tm->next)
		{
			tm2 = tm;
			tm = tm->next;
		}
		tm->next = *b_head;
		*b_head = tm;
		tm2->next = NULL;
	}
	return (swap_8(a_head, b_head, swap, operations));
}

int	swap_6(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 9 || swap == 11))
	{
		tm = *a_head;
		tm2 = *a_head;
		while (tm->next)
		{
			tm2 = tm;
			tm = tm->next;
		}
		tm->next = *a_head;
		*a_head = tm;
		tm2->next = NULL;
	}
	return (swap_7(a_head, b_head, swap, operations));
}

int	swap_2(t_stack **a_head, t_stack **b_head, int swap, int operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 2 || swap == 3))
	{
		tm = *b_head;
		temp = tm->content;
		tm = tm->next;
		(*b_head)->content = tm->content;
		tm->content = temp;
	}
	return (swap_3(a_head, b_head, swap, operations));
}
