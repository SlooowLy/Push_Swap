/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:07:34 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 16:07:36 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	last_swap(t_stack **a_head, int operations)
{
	int	i;
	int	k;

	i = get_min_place(*a_head);
	k = len(*a_head);
	while (!how_is_it(*a_head))
	{
		if (i < get_len(k))
			operations = swap(a_head, NULL, 6, operations);
		else
			operations = swap(a_head, NULL, 9, operations);
	}
	return (operations);
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
		return (0);
	return (1);
}

void	ft_free(t_stack **a_head, char ***av)
{
	int		i;
	t_stack	*tmp;

	i = 0;
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

void	second_creat(char **av2, t_stack **a_head, int k)
{
	long int	j;

	while (av2[k])
	{
		if (!check_safety(av2[k]))
			ft_free(a_head, &av2);
		j = ft_atoi(av2[k]);
		if (j > 2147483647 || j < -2147483648)
			ft_free(a_head, &av2);
		ft_lstadd_back(a_head, ft_lstnew(j));
		k++;
	}
}

char	**first_creat(char **av, char **av2, t_stack **a_head)
{
	long int	j;

	av2 = ft_split(av[1], ' ');
	if (!check_safety(av2[0]))
		ft_free(a_head, &av2);
	j = ft_atoi(av2[0]);
	if (j > 2147483647 || j < -2147483648)
		ft_free(a_head, &av2);
	*a_head = ft_lstnew(j);
	return (av2);
}
