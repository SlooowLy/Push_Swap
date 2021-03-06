/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:50:20 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 15:50:21 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus_lib.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			j = (unsigned char) s1[i] - (unsigned char) s2[i];
			return (j);
		}
		i++;
	}
	return (0);
}

int	check_operations(char *op)
{
	if (!ft_strncmp(op, "sa\n"))
		return (1);
	if (!ft_strncmp(op, "sb\n"))
		return (2);
	if (!ft_strncmp(op, "ss\n"))
		return (3);
	if (!ft_strncmp(op, "pa\n"))
		return (4);
	if (!ft_strncmp(op, "pb\n"))
		return (5);
	if (!ft_strncmp(op, "ra\n"))
		return (6);
	if (!ft_strncmp(op, "rb\n"))
		return (7);
	if (!ft_strncmp(op, "rr\n"))
		return (8);
	if (!ft_strncmp(op, "rra\n"))
		return (9);
	if (!ft_strncmp(op, "rrb\n"))
		return (10);
	if (!ft_strncmp(op, "rrr\n"))
		return (11);
	return (0);
}

void	ft_done_2(t_stack **h, int i)
{
	t_stack	*tmp;

	while (h && *h)
	{
		tmp = (*h)->next;
		free (*h);
		*h = tmp;
	}
	if (i)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	char	*operations;
	int		i;

	if (ac <= 1)
		exit(1);
	creat(&a_head, &b_head, av, ac);
	if (!check_double(a_head))
		ft_done_2(&a_head, 1);
	operations = get_next_line(0);
	while (operations != NULL)
	{
		free (operations);
		i = check_operations(operations);
		if (!i)
			ft_done_2(&a_head, 1);
		swap(&a_head, &b_head, i, 0);
		operations = get_next_line(0);
	}
	free (operations);
	print_resault(a_head);
	ft_done_2(&a_head, 0);
	ft_done_2(&b_head, 0);
	return (0);
}
