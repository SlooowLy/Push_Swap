/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fonctions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:37:23 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 17:37:24 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	swap_5(t_stack **a_head, t_stack **b_head, int swap, int *operations)
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
		if (swap == 7)
		{
			if (*operations <= -1)
				printf ("rb\n");
			else if (*operations > -1)
				(*operations)++;
		}
		if (swap == 8)
		{
			if (*operations <= -1)
				printf ("rr\n");
			else if (*operations > -1)
				(*operations)++;
		}
	}
	swap_6(a_head, b_head, swap, operations);
}

void	swap_8(t_stack **a_head, t_stack **b_head, int swap, int *operations)
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
		if (*operations <= -1)
			printf ("pa\n");
		else if (*operations > -1)
			(*operations)++;
	}
}

void	swap_4(t_stack **a_head, t_stack **b_head, int swap, int *operations)
{
	int		temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 6 || swap == 8))
	{
		tm = *a_head;
		while (tm->next)
			tm = tm->next;
		tm->next = *a_head;
		tm2 = (*a_head)->next;
		(*a_head)->next = NULL;
		*a_head = tm2;
		if (swap == 6)
		{
			if (*operations <= -1)
				printf ("ra\n");
			else if (*operations > -1)
				(*operations)++;
		}
	}
	swap_8(a_head, b_head, swap, operations);
	swap_5(a_head, b_head, swap, operations);
}

void	swap_3(t_stack **a_head, t_stack **b_head, int swap, int *operations)
{
	int		temp;
	t_stack	*tm;

	if (checker(swap, a_head, b_head) && (swap == 5))
	{
		if (*b_head)
		{
			tm = *a_head;
			ft_lstadd_front(b_head, ft_lstnew(tm->content));
			tm = tm->next;
			free (*a_head);
			*a_head = tm;
		}
		else
		{
			*b_head = ft_lstnew((*a_head)->content);
			tm = *a_head;
			tm = tm->next;
			free (*a_head);
			*a_head = tm;
		}
		if (*operations <= -1)
			printf ("pb\n");
		else if (*operations > -1)
			(*operations)++;
	}
	swap_4(a_head, b_head, swap, operations);
}

void	swap(t_stack **a_head, t_stack **b_head, int swap, int	*operations)
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
		if (swap == 1)
		{
			if (*operations <= -1)
				printf ("sa\n");
			else if (*operations > -1)
			(*operations)++;
		}
		if (swap == 3)
		{
			if (*operations <= -1)
				printf ("ss\n");
			else if (*operations > -1)
				(*operations)++;
		}
	}
	swap_2(a_head, b_head, swap, operations);
}
