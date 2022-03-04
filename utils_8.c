/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:26:32 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 18:26:33 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	print_op_4(int swap, int operations)
{
	if (swap == 4)
	{
		if (operations <= -1)
			write (1, "pa\n", 3);
		else if (operations > -1)
			(operations)++;
	}
	return (operations);
}

int	print_op_3(int swap, int operations)
{
	if (swap == 2)
	{
		if (operations <= -1)
			write (1, "sb\n", 3);
		else if (operations > -1)
			(operations)++;
	}
	if (swap == 5)
	{
		if (operations <= -1)
			write (1, "pb\n", 3);
		else if (operations > -1)
			(operations)++;
	}
	if (swap == 1)
	{
		if (operations <= -1)
			write (1, "sa\n", 3);
		else if (operations > -1)
		(operations)++;
	}
	return (print_op_4(swap, operations));
}

int	print_op_2(int swap, int operations)
{
	if (swap == 10)
	{
		if (operations <= -1)
			write (1, "rrb\n", 4);
		else if (operations > -1)
		(operations)++;
	}
	if (swap == 11)
	{
		if (operations <= -1)
			write (1, "rrr\n", 4);
		else if (operations > -1)
		(operations)++;
	}
	if (swap == 9)
	{
		if (operations <= -1)
			write (1, "rra\n", 4);
		else if (operations > -1)
			(operations)++;
	}
	return (print_op_3(swap, operations));
}

int	print_op(int swap, int operations)
{
	if (swap == 7)
	{
		if (operations <= -1)
			write (1, "rb\n", 3);
		else if (operations > -1)
			(operations)++;
	}
	if (swap == 8)
	{
		if (operations <= -1)
			write (1, "rr\n", 3);
		else if (operations > -1)
			(operations)++;
	}
	if (swap == 6)
	{
		if (operations <= -1)
			write (1, "ra\n", 3);
		else if (operations > -1)
			(operations)++;
	}
	return (print_op_2(swap, operations));
}
