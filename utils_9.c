/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:15:30 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/06 10:15:31 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_done(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (*a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free (*a);
			*a = tmp;
		}
	}
	if (*b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free (*b);
			*b = tmp;
		}
	}
}

int	check_double(t_stack *a_head)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a_head;
	while (tmp)
	{
		i = tmp->content;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->content == i)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_done_2(t_stack **h)
{
	t_stack	*tmp;

	while (*h)
	{
		tmp = (*h)->next;
		free (*h);
		*h = tmp;
	}
	write (2, "Error\n", 6);
	exit (1);
}
