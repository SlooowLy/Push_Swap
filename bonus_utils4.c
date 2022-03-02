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

void	second_creat(char **av2, t_stack **a_head, int k)
{
	int	j;

	while (av2[k])
	{
		if (!check_safety(av2[k]))
			ft_free(a_head, av2);
		j = ft_atoi(av2[k]);
		if (j > 2147483647 || j < -2147483648)
			ft_free(a_head, av2);
		ft_lstadd_back(a_head, ft_lstnew(j));
		k++;
	}
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
		print_op(swap, operations);
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
		if (swap == 3)
		{
			if (*operations <= -1)
				printf ("ss\n");
			else if (*operations > -1)
				(*operations)++;
		}
		print_op(swap, operations);
	}
	swap_2(a_head, b_head, swap, operations);
}

void	print_op(int swap, int *operations)
{
	if (swap == 7)
	{
		if (*operations <= -1)
			write (1, "rb\n", 3);
		else if (*operations > -1)
			(*operations)++;
	}
	if (swap == 8)
	{
		if (*operations <= -1)
			write (1, "rr\n", 3);
		else if (*operations > -1)
			(*operations)++;
	}
	if (swap == 6)
	{
		if (*operations <= -1)
			printf ("ra\n");
		else if (*operations > -1)
			(*operations)++;
	}
	print_op_2(swap, operations);
}
