/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:18:35 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 18:18:36 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	firs_algo(t_stack *a_head, t_stack *b_head, char **av, int operations)
{
	t_stack	*mark_head;
	int		i;

	mark_head = get_mark_head(&a_head);
	mark(&a_head, &b_head, mark_head);
	operations = push_to_b(&a_head, &b_head, operations);
	operations = sort_from_b_to_a(&a_head, &b_head, operations);
	last_swap(&a_head, operations);
	return (operations);
}

void	second_algo_utils(t_stack **a_head)
{
	int	i;

	i = -1;
	if (!how_is_it(*a_head))
	{
		if ((*a_head)->content == get_min(*a_head))
		{
			swap(a_head, NULL, 1, i);
			swap(a_head, NULL, 6, i);
		}
		else if ((*a_head)->content == get_max(*a_head))
		{
			swap(a_head, NULL, 6, i);
			if (!how_is_it(*a_head))
				swap(a_head, NULL, 1, i);
		}
		else
		{
			if ((*a_head)->next->content > (*a_head)->next->next->content)
				swap(a_head, NULL, 9, i);
			else
				swap(a_head, NULL, 1, i);
		}
	}
}

void	second_algo(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int	min;
	int	i;
	int	j;
	int	k;

	i = -2;
	k = 0;
	j = len(*a_head) / 2;
	while (k != 2)
	{
		min = get_min(*a_head);
		while ((*a_head)->content != min)
		{
			if (get_min_place(*a_head) <= j)
				swap(a_head, b_head, 6, i);
			else if (get_min_place(*a_head) > j)
				swap(a_head, b_head, 9, i);
		}
		swap(a_head, b_head, 5, i);
		k++;
	}
	second_algo_utils(a_head);
	swap (a_head, b_head, 4, i);
	swap (a_head, b_head, 4, i);
}

void	therd_algo(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int	i;

	i = -2;
	if (!how_is_it(*a_head))
	{
		if ((*a_head)->content == get_min(*a_head))
		{
			swap(a_head, NULL, 1, i);
			swap(a_head, NULL, 6, i);
		}
		else if ((*a_head)->content == get_max(*a_head))
		{
			swap(a_head, NULL, 6, i);
			if (!how_is_it(*a_head))
				swap(a_head, NULL, 1, i);
		}
		else
		{
			if ((*a_head)->next->content > (*a_head)->next->next->content)
				swap(a_head, NULL, 9, i);
			else
				swap(a_head, NULL, 1, i);
		}
	}
	i = 0;
	// while (av[i])
	// {
	// 	free (av[i]);
	// 	i++;
	// }
	// free (av);
}

void	norm_function(char **av, int ac)
{
	int		i;
	int		j;
	t_stack	*a_tmp;
	t_stack	*b_tmp;
	t_stack *a_head;
	t_stack *b_head;

	creat(&a_head, &b_head, av, ac);
	creat(&a_tmp, &b_tmp, av, ac);
	j = firs_algo(a_head, b_head, av, 0);
	i = len(a_head);
	if (i < 101)
	{
		if (j > 700)
			i = firs_algo(a_tmp, b_tmp, av, -1);
		else
			i = firs_algo(a_tmp, b_tmp, av, -2);
	}
	else
	{
		if (j > 5500)
			i = firs_algo(a_tmp, b_tmp, av, -1);
		else
			i = firs_algo(a_tmp, b_tmp, av, -2);
	}
	ft_done(&a_head, &b_head);
	ft_done(&a_tmp, &b_tmp);
}
