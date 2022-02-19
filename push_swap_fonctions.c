/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fonctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:32:32 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 17:32:35 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

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

void	swap_7(t_stack **a_head, t_stack **b_head, int swap)
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
		if (swap == 10)
			printf ("rrb\n");
		if (swap == 11)
			printf ("rrr\n");
	}
}

void	swap_6(t_stack **a_head, t_stack **b_head, int swap)
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
		if (swap == 9)
			printf ("rra\n");
	}
	swap_7(a_head, b_head, swap);
}

void	swap_2(t_stack **a_head, t_stack **b_head, int swap)
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
		if (swap == 2)
			printf ("sb\n");
	}
	swap_3(a_head, b_head, swap);
}
