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

static int	ft_second(const char *a, int r, int i)
{
	int	p;

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

int	ft_atoi(const char *str)
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
	if (lenq (str, i) > 10 && j == 1)
		return (0);
	if (lenq (str, i) > 10 && j == -1)
		return (-1);
	r = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (ft_second(str, r, i) * j);
}
