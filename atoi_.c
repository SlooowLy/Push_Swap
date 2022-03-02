/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:40:59 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/19 17:41:00 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

long int	ft_second(const char *a, int r, int i)
{
	long int	p;

	p = 0;
	while (i - r != 0)
	{
		p = p * 10 + a[r++] - 48;
	}
	return (p);
}

static int	lenq(const char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		i++;
		j++;
	}
	return (j);
}

long int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	r;

	j = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		j = -1;
		i++;
	}
	r = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (ft_second(str, r, i) * j);
}

int	how_is_it(t_stack *a_head)
{
	int		i;
	t_stack	*the_next;

	i = 0;
	if (a_head != NULL)
	{
		while (a_head->next)
		{
			the_next = a_head->next;
			if (the_next->content < a_head->content)
				return (0);
			a_head = the_next;
		}
	}
	else
		return (0);
	return (1);
}
