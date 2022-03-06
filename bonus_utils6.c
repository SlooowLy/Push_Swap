/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 06:51:14 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/06 06:51:15 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus_lib.h"

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

void	ft_free(t_stack **a_head, char ***av)
{
	t_stack	*tmp;

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

char	**first_creat(char **av, char **av2, t_stack **a_head)
{
	int	j;

	av2 = ft_split(av[1], ' ');
	if (!check_safety(av2[0]))
		ft_free(a_head, &av2);
	j = ft_atoi(av2[0]);
	if (j > 2147483647 || j < -2147483648)
		ft_free(a_head, &av2);
	*a_head = ft_lstnew(j);
	return (av2);
}
