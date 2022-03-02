/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:02:25 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 14:02:26 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus_lib.h"

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
		return (0);
	return (1);
}

void	ft_free(t_stack **a_head, char **av)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	if (av)
	{
		while (av[++i])
			free(av[i]);
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
	double	j;
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
