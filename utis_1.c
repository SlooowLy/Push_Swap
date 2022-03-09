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

void	creat_25_line(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	char	**av2;
	int		i;
	int		k;
	int		j;

	k = 1;
	i = 1;
	*b_head = NULL;
	if (ac > 1)
	{
		av2 = first_creat(av, av2, a_head);
		while (av[i])
		{
			j = 0;
			if (i != 1)
				av2 = ft_split(av[i], ' ');
			second_creat(av2, a_head, k);
			while (av2[j])
				free(av2[j++]);
			free (av2);
			av2 = NULL;
			i++;
			k = 0;
		}
	}
}

int	creat(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int		i;

	if (ac > 1)
	{
		creat_25_line(a_head, b_head, av, ac);
		return (1);
	}
	i = 0;
	return (0);
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
		if (k > i)
		{
			i = k;
			mark_head = *a_head;
		}
		*a_head = (*a_head)->next;
	}
	*a_head = head;
	return (mark_head);
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
	head = *a_head;
	*a_head = mark_head;
	(*a_head)->true = 1;
	tmp = *a_head;
	*a_head = (*a_head)->next;
	while (*a_head != mark_head && *a_head)
	{
		if ((*a_head)->content > tmp->content)
		{
			(*a_head)->true = 1;
			tmp = *a_head;
		}
		*a_head = (*a_head)->next;
		if (!tmp && head != mark_head)
			tmp = head;
		if ((*a_head) == NULL && head != mark_head)
			*a_head = head;
	}
	*a_head = head;
}
