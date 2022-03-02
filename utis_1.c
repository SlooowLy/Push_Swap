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

void	last_swap(t_stack **a_head, int *operations)
{
	int	i;
	int	k;

	i = get_min_place(*a_head);
	k = len(*a_head);
	while (!how_is_it(*a_head))
	{
		if (i < get_len(k))
			swap(a_head, NULL, 6, operations);
		else
			swap(a_head, NULL, 9, operations);
	}
}

int	check_safety(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		k++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (k == 1 && i == 1)
		return (0);
	if (k > 1)
		return(0);
	return (1);
}

void	ft_free(t_stack **a_head, char **av)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	if (av)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	if (*a_head)
	{
		while (*a_head)
		{
			tmp = (*a_head)->next;
			free (*a_head);
			*a_head = tmp;
		}
	}
	write (2, "Error\n", 6);
	exit (1);
}

int	creat(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int		i;
	int		k;
    long	int	j;
	char	**av2;

	i = 1;
	k = 1;
	if (ac > 1)
	{
		*b_head = NULL;
		if (ac > 1)
		{
			av2 = ft_split(av[i], ' ');
			if (!check_safety(av2[0]))
				ft_free(a_head, av2);
            j = ft_atoi(av2[0]);
            if (j > 2147483647 || j < -2147483648)
                ft_free(a_head, av2);
			*a_head = ft_lstnew(j);
			while (av[i])
			{
				if (i != 1)
					av2 = ft_split(av[i], ' ');
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
				i++;
				k = 0;
			}
		}
		return (1);
	}
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

void	mark_2(t_stack **a_head, t_stack *mark_head)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*first_tmp;
	t_stack	*head;

	head = *a_head;
	*a_head = mark_head;
	tmp = (*a_head)->next;
	first_tmp = *a_head;
	*a_head = (*a_head)->next->next;
	while (*a_head != mark_head && *a_head)
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
		if (head != mark_head && !(*a_head))
			*a_head = head;
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
	// mark_2(a_head, mark_head);
	*a_head = head;
}
