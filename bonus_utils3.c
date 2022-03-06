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

char	**first_creat(char **av, char **av2, t_stack **a_head)
{
	int	j;

	av2 = ft_split(av[1], ' ');
	if (!check_safety(av2[0]))
		ft_free(a_head, av2);
	j = ft_atoi(av2[0]);
	if (j > 2147483647 || j < -2147483648)
		ft_free(a_head, av2);
	*a_head = ft_lstnew(j);
	return (av2);
}

void	creat_25_line(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	char	**av2;
	int		i;
	int		k;
	int		j;

	k = 1;
	i = 1;
	j = 0;
	*b_head = NULL;
	if (ac > 1)
	{
		av2 = first_creat(av, av2, a_head);
		while (av[i])
		{
			if (i != 1)
				av2 = ft_split(av[i], ' ');
			second_creat(av2, a_head, k);
			while (av2[j])
				free(av2[j++]);
			free (av2);
			i++;
			k = 0;
			j = 0;
		}
	}
}

int	creat(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	// int		i;

	if (ac > 1)
	{
		creat_25_line(a_head, b_head, av, ac);
		return (1);
	}
	return (0);
}
