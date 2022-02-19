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

void	swap_5(t_stack **a_head, t_stack **b_head, int swap)
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
			printf ("rb\n");
		if (swap == 8)
			printf ("rr\n");
	}
	swap_6(a_head, b_head, swap);
}

void	swap_8(t_stack **a_head, t_stack **b_head, int swap)
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
		printf ("pa\n");
	}
}

void	swap_4(t_stack **a_head, t_stack **b_head, int swap)
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
			printf ("ra\n");
	}
	swap_8(a_head, b_head, swap);
	swap_5(a_head, b_head, swap);
}

void	swap_3(t_stack **a_head, t_stack **b_head, int swap)
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
		printf ("pb\n");
	}
	swap_4(a_head, b_head, swap);
}

void	swap(t_stack **a_head, t_stack **b_head, int swap)
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
			printf ("sa\n");
		if (swap == 3)
			printf ("ss\n");
	}
	swap_2(a_head, b_head, swap);
}
