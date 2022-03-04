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

void	print_op_2(int swap, int *operations)
{
	if (swap == 10)
	{
		if (*operations <= -1)
			printf ("rrb\n");
		else if (*operations > -1)
		(*operations)++;
	}
	if (swap == 11)
	{
		if (*operations <= -1)
			printf ("rrr\n");
		else if (*operations > -1)
		(*operations)++;
	}
	if (swap == 9)
	{
		if (*operations <= -1)
			printf ("rra\n");
		else if (*operations > -1)
			(*operations)++;
	}
	print_op_3(swap, operations);
}

void	check_double(t_stack **a_head)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a_head;
	while (tmp)
	{
		i = tmp->content;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->content == i)
				ft_free(a_head, NULL);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	print_op_3(int swap, int *operations)
{
	if (swap == 2)
	{
		if (*operations <= -1)
			printf ("sb\n");
		else if (*operations > -1)
			(*operations)++;
	}
	if (swap == 5)
	{
		if (*operations <= -1)
			printf ("pb\n");
		else if (*operations > -1)
			(*operations)++;
	}
	if (swap == 1)
	{
		if (*operations <= -1)
			printf ("sa\n");
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
		print_op(swap, operations);
	}
	swap_8(a_head, b_head, swap, operations);
	swap_5(a_head, b_head, swap, operations);
}

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
		print_op(swap, operations);
	}
	swap_6(a_head, b_head, swap, operations);
}
