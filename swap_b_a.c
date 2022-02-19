#include "push_swap_lib.h"

void	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op, int min)
{
	int	i;

	if (!check_b_a(*a_head, *b_head, first, min))
	{
		if (op->oa == 0 && op->ob == 1)
			while (!check_b_a (*a_head, *b_head, first, min))
				swap(a_head, b_head, 10);
		if (op->oa == 0 && op->ob == 2)
			while (!check_b_a (*a_head, *b_head, first, min))
				swap(a_head, b_head, 7);
		if (op->oa == 1 && op->ob == 0)
			while (!check_b_a (*a_head, *b_head, first, min))
				swap(a_head, b_head, 6);
		if (op->oa == 1 && op->ob == 1)
		{
			while (!check_b(*b_head, first) && !check_a(*a_head, first, min))
				swap (a_head, b_head, 11);
			if (!check_a(*a_head, first, min))
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 9);
			else
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 10);
		}
		if (op->oa == 1 && op->ob == 2)
		{
			i = check_1_2(op, 100000, *a_head, *b_head);
			if (i)
			{
				if (i == 3)
				{
					while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
						swap(a_head, b_head, 11);
					if (!check_a(*a_head, first, min))
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 9);
					else
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 10);
				}
				else if (i == 4)
				{
					while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
					{
						swap(a_head, b_head, 8);
					}
					if (!check_a(*a_head, first, min))
						while (!check_b_a(*a_head, *b_head, first, min))
						{
							swap(a_head, b_head, 6);
						}
					else
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 7);
				}
			}
			else
			{
				while (!check_a(*a_head, first, min))
					swap(a_head, b_head, 9);
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 7);
			}
		}
		if (op->oa == 2 && op->ob == 0)
		{
			while (!check_b_a(*a_head, *b_head, first, min))
				swap(a_head, b_head, 6);
		}
		if (op->oa == 2 && op->ob == 1)
		{
			i = check_1_2(op, 10000, *a_head, *b_head);
			if (i)
			{
				if (i == 3)
				{
					while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
						swap(a_head, b_head, 11);
					if (!check_a(*a_head, first, min))
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 9);
					else
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 10);
				}
				else if (i == 4)
				{
					while (!check_a(*a_head, first, min) && !check_b(*b_head, first))
						swap(a_head, b_head, 8);
					if (!check_a(*a_head, first, min))
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 6);
					else
						while (!check_b_a(*a_head, *b_head, first, min))
							swap(a_head, b_head, 7);
				}
			}
			else
			{
				while (!check_b(*b_head, first))
					swap(a_head, b_head, 10);
				while (!check_a(*a_head, first, min))
					swap(a_head, b_head, 6);
			}
		}
		if (op->oa == 2 && op->ob == 2)
		{
			if (op->a > op->b)
			{
				while (!check_b(*b_head, first))
					swap (a_head, b_head, 8);
				while (!check_b_a(*a_head, *b_head, first, min))
					swap(a_head, b_head, 6);
			}
			else
				while (!check_a(*a_head, first, min))
					swap (a_head, b_head, 8);
				while (!check_b_a(*a_head, *b_head, first, min))
					swap (a_head, b_head, 7);
		}
	}
	swap (a_head, b_head, 4);
}