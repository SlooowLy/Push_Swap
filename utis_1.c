/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:46:36 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:37 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	last_swap(t_stack **a_head)
{
	int	i;
	int	k;

	i = get_min_place(*a_head);
	k = len(*a_head);
	while (!how_is_it(*a_head))
	{
		if (i < k / 2 + 1)
			swap(a_head, NULL, 6);
		else
			swap(a_head, NULL, 9);
	}
}

void	creat(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int	i;

	i = 1;
	*a_head = ft_lstnew(ft_atoi(av[1]));
	*b_head = NULL;
	while (i < ac - 1)
	{
		ft_lstadd_back(a_head, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
}

int	how_is_it(t_stack *a_head)
{
	int		i;
	t_stack	*the_next;

	i = 0;
	while (a_head->next)
	{
		the_next = a_head->next;
		if (the_next->content < a_head->content)
			return (0);
		a_head = the_next;
	}
	return (1);
}

t_stack	*get_mark_head(t_stack **a_head)
{
	t_stack	*head;
	t_stack	*mark_head;
	int		i;
	int		k;

	i = 0;
	head = *a_head;
	while (*a_head)
	{
		k = will_stay(head, *a_head, 1, 0);
		if (k > i || (k == i && mark_head->content < (*a_head)->content))
		{
			i = k;
			mark_head = *a_head;
		}
		*a_head = (*a_head)->next;
	}
	*a_head = head;
	return (mark_head);
}

void	mark_2(t_stack **a_head)
{
	t_stack	*mark_head;
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*first_tmp;

	mark_head = *a_head;
	tmp = (*a_head)->next;
	first_tmp = *a_head;
	*a_head = (*a_head)->next->next;
	while (*a_head)
	{
		if (!(*a_head)->true && (*a_head)->content > first_tmp->content && tmp->true && first_tmp->true)
		{
			(*a_head)->true = 1;
			first_tmp = *a_head;
		}
		else
		{
			first_tmp = tmp;
			tmp = *a_head;
		}
		*a_head = (*a_head)->next;
	}
}

int	get_mark_head_place(t_stack *a_haed, t_stack *mark_head)
{
	int	i;

	i = 0;
	while (a_haed != mark_head)
	{
		i++;
		a_haed = a_haed->next;
	}
	return (i);
}

void	mark(t_stack **a_head, t_stack **b_head, t_stack *mark_head)
{
	t_stack	*tmp;
	t_stack	*head;
	int		i;

	i = 0;
	if (get_mark_head_place(*a_head, mark_head) > len(*a_head) / 2 + 1)
		i = 1;
	while (*a_head != mark_head)
	{
		if (i)
			swap(a_head, NULL, 9);
		else
			swap(a_head, NULL, 6);
	}
	(*a_head)->true = 1;
	tmp = *a_head;
	*a_head = (*a_head)->next;
	while (*a_head)
	{
		if ((*a_head)->content > tmp->content)
		{
			(*a_head)->true = 1;
			tmp = *a_head;
		}
		*a_head = (*a_head)->next;
	}
	*a_head = mark_head;
	mark_2(a_head);
	*a_head = mark_head;
}
