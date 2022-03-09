/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:04:37 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 18:04:39 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	sort_from_b_to_a(t_stack **a_head, t_stack **b_head, int operations)
{
	int		i;
	t_op	op;
	t_stack	*first;

	i = 0;
	op.o = 0;
	op.operations = operations;
	while (*b_head)
	{
		first = *b_head;
		if ((*b_head)->next)
			first = whos_first(*a_head, *b_head, &op, op.operations);
		op.operations = swap_b_a(a_head, b_head, first, &op);
	}
	return (op.operations);
}

int	get_min_place(t_stack *a_head)
{
	int	i;
	int	k;

	i = 0;
	k = get_min(a_head);
	while (k != a_head->content)
	{
		i++;
		a_head = a_head->next;
	}
	return (i);
}

void	check_split(char const *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!s[0])
	{
		write (2, "ERROR\n", 6);
		exit (1);
	}
	while (s[i])
	{
		if (s[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
	{
		write (2, "ERROR\n", 6);
		exit (1);
	}
}
