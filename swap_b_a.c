/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:13:51 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/20 19:13:52 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

// void	swap_i_3_2(t_stack **a_head, t_stack **b_head, t_stack *first, int min)
// {
// 	while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
// 		swap(a_head, b_head, 11, operations);
// 	if (!check_a(*a_head, first, min))
// 		while (!check_b_a(*a_head, *b_head, first, min))
// 			swap(a_head, b_head, 9, operations);
// 	else
// 		while (!check_b_a(*a_head, *b_head, first, min))
// 			swap(a_head, b_head, 10, operations);
// }

// void	swap_i_4_2(t_stack **a_head, t_stack **b_head, t_stack *first, int min)
// {
// 	while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
// 		swap(a_head, b_head, 8, operations);
// 	if (!check_a(*a_head, first, min))
// 		while (!check_b_a(*a_head, *b_head, first, min))
// 			swap(a_head, b_head, 6, operations);
// 	else
// 		while (!check_b_a(*a_head, *b_head, first, min))
// 			swap(a_head, b_head, 7, operations);
// }

// void	swap_b_a_3(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
// {
// 	int	i;
// 	int	min;

// 	min = get_min_2(*a_head, *b_head);
// 	if (op->oa == 2 && op->ob == 1)
// 	{
// 		i = check_1_2(op, 10000, *a_head, *b_head);
// 		if (op->o)
// 		{
// 			if (op->o == 3)
// 				swap_i_3_2(a_head, b_head, first, min);
// 			else if (op->o == 4)
// 				swap_i_4_2(a_head, b_head, first, min);
// 		}
// 		else
// 		{
// 			while (!check_b(*b_head, first))
// 				swap(a_head, b_head, 10, operations);
// 			while (!check_a(*a_head, first, min))
// 				swap(a_head, b_head, 6, operations);
// 		}
// 	}
// }

// void	swap_b_a_4(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
// {
// 	int	min;

// 	min = get_min_2(*a_head, *b_head);
// 	if (op->oa == 2 && op->ob == 0)
// 	{
// 		while (!check_b_a(*a_head, *b_head, first, min))
// 			swap(a_head, b_head, 6, operations);
// 	}
// 	if (op->oa == 2 && op->ob == 2)
// 	{
// 		if (op->a > op->b)
// 		{
// 			while (!check_b(*b_head, first))
// 				swap (a_head, b_head, 8, operations);
// 			while (!check_b_a(*a_head, *b_head, first, min))
// 				swap(a_head, b_head, 6, operations);
// 		}
// 		else
// 		{
// 			while (!check_a(*a_head, first, min))
// 				swap (a_head, b_head, 8, operations);
// 			while (!check_b_a(*a_head, *b_head, first, min))
// 				swap (a_head, b_head, 7, operations);
// 		}		
// 	}
// }

void	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op)
{
	int	i;
	int	min;
	int	lenb;
	int	lena;
	int	*operations;

	min = get_min_2(*a_head, *b_head);
	lenb = len(*b_head);
	lena = len(*a_head);
	operations = op->operations;
	if (!check_b_a(*a_head, *b_head, first, min))
	{
		// swap_b_a_1(a_head, b_head, first, op);
		// swap_b_a_2(a_head, b_head, first, op);
		// swap_b_a_3(a_head, b_head, first, op);
		// swap_b_a_4(a_head, b_head, first, op);
		if (op->o == 1)
		{
			while (!check_b(*b_head, first) && !check_a(*a_head, first, min))
				swap (a_head, b_head, 8, operations);
			if (!check_a(*a_head, first, min))
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 6, operations);
			else
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 7, operations);
		}
		if (op->o == 0)
		{
			while (!check_b(*b_head, first) && !check_a(*a_head, first, min))
				swap (a_head, b_head, 11, operations);
			if (!check_a(*a_head, first, min))
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 9, operations);
			else
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 10, operations);
		}
		if (op->o == 2)
		{
			while (!check_a(*a_head, first, min))
					swap (a_head, b_head, 9, operations);
			while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 7, operations);
		}
		if (op->o == 3)
		{
			while (!check_a(*a_head, first, min))
					swap (a_head, b_head, 6, operations);
			while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 10, operations);
		}
	}
	swap (a_head, b_head, 4, operations);
}
