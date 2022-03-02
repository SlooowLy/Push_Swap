/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:17:08 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/20 19:17:10 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	print_the_stack(t_stack *stack)
{
	printf ("%d ", stack->content);
	while (stack->next)
	{
		stack = stack->next;
		printf ("%d ", stack->content);
	}
}

int	get_i_3(t_op *op, int lena, int lenb, int i)
{
	int	a;
	int	b;
	int	j;
	int	k;

	if (op->oa == 2 && op->ob == 1)
	{
		a = (lena - op->a) + 1;
		b = (lenb - op->b) + 1;
		j = a;
		if (j < b)
			j = b;
		k = op->b;
		if (k < op->a)
			k = op->a;
		i = k;
		if (j < i)
			i = j;
		if (i > (lenb - op->b) + op->a + 1)
			i = (lenb - op->b) + op->a + 1;
	}
	return (i);
}

int	op_number(t_op *op, int lena, int lenb)
{
	int	i;
	int	j;
	int	k;
	int	a;
	int	b;

	i = 100000;
	i = get_i_1(op, lena, lenb, i);
	i = get_i_2(op, lena, lenb, i);
	i = get_i_3(op, lena, lenb, i);
	if (op->oa == 2 && op->ob == 2)
	{
		if (op->a < op->b)
			i = op->b;
		if (op->a >= op->b)
			i = op->a;
	}
	return (i);
}

void	f_u_25_line(t_stack *a_head, t_stack *b_head, t_op *op, t_25_line_2 *t)
{
	t_stack	*tmp;

	tmp = a_head;
	t->b = b_head->content;
	op->a = 0;
	while (tmp)
	{
		if (t->b < tmp->content && tmp->content == get_min(a_head))
		{
			break ;
		}
		if (tmp == a_head && check_first_last(a_head, t->b))
		{
			break ;
		}
		if (tmp != a_head)
		{
			if (t->t < t->b && t->b < tmp->content)
			{
				// op->a += 1;
				break ;
			}
		}
		t->t = tmp->content;
		op->a += 1;
		tmp = tmp->next;
	}
}

int	get_len(double	ln)
{
	int		i;
	int		k;
	double	j;

	k = ln / 2;
	j = ln / 2;
	if (k != j)
		return (ln / 2 + 1);
	return (ln / 2);
}

// 0 -> bjoj lt7t
// 1 -> bjoj lfo9
// 2 -> a lt7t
// 3 -> b lt7t
int	get_op_2(int lena, int lenb, t_op *op, int operations)
{
	int	i;
	
	i = 0;
	if (lena - op->a > lenb - op->b)
		i = lena - op->a + 1;
	else
		i = lenb - op->b + 1;
	op->o = 0;
	if (op->a >= op->b)
	{
		if (i > op->a)
		{
			i = op->a;
			op->o = 1;
		}
	}
	else
	{
		if (i > op->b)
		{
			i = op->b;
			op->o = 1;
		}
	}
	if (i != -1)
	{
		if (i > (lena - op->a) + op->b + 1)
		{
			op->o = 2;
			i = (lena - op->a) + op->b + 1;
		}
		if (i > (lenb - op->b) + op->a + 1)
		{
			op->o = 3;
			i = (lenb - op->b) + op->a + 1;
		}
	}
	else
	{
		if (i > (lena - op->a) + op->b + 1)
		{
			op->o = 2;
			i = (lena - op->a) + op->b + 1;
		}
		if (i > (lenb - op->b) + op->a + 1)
		{
			op->o = 3;
			i = (lenb - op->b) + op->a + 1;
		}		
	}
	return (i);
}

t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int operations)
{
	t_25_line_2	t;
	t_stack		*first;
	t_op		ret;

	op->b = 0;
	op->a = 0;
	t.k = 1000000;
	t.lena = len(a_head);
	t.lenb = len(b_head);
	while (b_head)
	{
		f_u_25_line(a_head, b_head, op, &t);
		// get_op(t.lena, t.lenb, op);
		// t.r = op_number(op, t.lena, t.lenb);
		t.r = get_op_2(t.lena, t.lenb, op, operations);
		if (t.k > t.r )
		{
			ret = *op;
			first = b_head;
			t.k = t.r;
		}
		if (t.k >= t.r && operations == -1)
		{
			ret = *op;
			first = b_head;
			t.k = t.r;
		}
		op->b += 1;
		b_head = b_head->next;
	}
	*op = ret;
	return (first);
}

int	how_is_it_2(t_stack *mark_head, t_stack *a_haed)
{
	t_stack *tmp_first;
	t_stack *tmp;
	int		i;

	i = 0;
	tmp_first = mark_head;
	tmp = a_haed;
	if (mark_head->next)
		tmp = tmp_first->next;
	if (a_haed != mark_head)
		i = 1;
	while (tmp != mark_head && tmp)
	{
		if (tmp->content < tmp_first->content)
			return (0);
		tmp_first = tmp_first->next;
		tmp = tmp->next;
		if (i && tmp)
			tmp = a_haed;
		if (i && !tmp_first)
			tmp_first = a_haed;
	}
	return (1);
}

int	get_swap(t_stack *head, t_stack *tmp)
{
	int	i;
	int	k;

	i = len (head);
	k = 0;
	while (head != tmp)
	{
		k++;
		head = head->next;
	}
	if (k <= get_len(i))
		return (1);
	return (0);
}

// void	sort_in_a(t_stack **a_head, t_stack *mark_head)
// {
// 	t_stack	*tmp;
// 	t_stack	*head;
// 	t_stack	*first_head;
// 	int		i;
// 	int		ln;

// 	head = *a_head;
// 	tmp = *a_head;
// 	*a_head = (*a_head)->next;
// 	ln = len(tmp);
// 	while (*a_head)
// 	{
// 		if ((*a_head)->content < tmp->content && (*a_head)->content != mark_head->content)
// 		{
// 			i = get_swap(head, tmp);
// 			*a_head = head;
// 			while (*a_head != tmp)
// 			{
// 				if (i)
// 					swap(a_head, NULL, 6);
// 				else
// 					swap(a_head, NULL, 9);
// 			}
// 			swap(a_head, NULL, 1);
// 			head = *a_head;
// 			*a_head = (*a_head)->next;
// 		}
// 		tmp = *a_head;
// 		*a_head = (*a_head)->next;
// 	}
// 	*a_head = head;
// }

void	check_double(t_stack **a_head)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a_head;
	while (tmp)
	{
		i = tmp->content;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->content == i)
				ft_free(a_head, NULL);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	firs_algo(t_stack *a_head, t_stack *b_head, char **av, int operations)
{
	t_stack	*mark_head;
	int		i;

	mark_head = get_mark_head(&a_head);
	mark(&a_head, &b_head, mark_head);
	i = get_min(a_head);
	push_to_b(&a_head, &b_head, mark_head, &operations);
	// sort_in_a(&a_head, mark_head);
	sort_from_b_to_a(&a_head, &b_head, i, &operations);
	last_swap(&a_head, &operations);
	return (operations);
}

void second_algo(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int	min;
	int	i;
	int	j;
	int	k;

	i = -2;
	k = 0;
	j = len(*a_head) / 2;
	while (k != 2)
	{
		min = get_min(*a_head);
		while ((*a_head)->content != min)
		{
			if (get_min_place(*a_head) <= j)
				swap(a_head, b_head, 6, &i);
			else if (get_min_place(*a_head) > j)
				swap(a_head, b_head, 9, &i);
		}
		swap(a_head, b_head, 5, &i);
		k++;
	}
	if (!how_is_it(*a_head))
	{
		if ((*a_head)->content == get_min(*a_head))
		{
			swap(a_head, NULL, 1, &i);
			swap(a_head, NULL, 6, &i);
		}
		else if ((*a_head)->content == get_max(*a_head))
		{
			swap(a_head, NULL, 6, &i);
			if (!how_is_it(*a_head))
				swap(a_head, NULL, 1, &i);
		}
		else
		{
			if ((*a_head)->next->content > (*a_head)->next->next->content)
				swap(a_head, NULL, 9, &i);
			else
				swap(a_head, NULL, 1, &i);
		}
	}
	swap (a_head, b_head, 4, &i);
	swap (a_head, b_head, 4, &i);
}

void therd_algo(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int	i;

	i = -2;
	if (!how_is_it(*a_head))
	{
		if ((*a_head)->content == get_min(*a_head))
		{
			swap(a_head, NULL, 1, &i);
			swap(a_head, NULL, 6, &i);
		}
		else if ((*a_head)->content == get_max(*a_head))
		{
			swap(a_head, NULL, 6, &i);
			if (!how_is_it(*a_head))
				swap(a_head, NULL, 1, &i);
		}
		else
		{
			if ((*a_head)->next->content > (*a_head)->next->next->content)
				swap(a_head, NULL, 9, &i);
			else
				swap(a_head, NULL, 1, &i);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*a_tmp;
	t_stack	*b_tmp;
	t_stack	*b_head;
	int	i;

	if (ac <= 1)
	{
		write (1, "Error\n", 6);
		exit(0);
	}
	creat(&a_head, &b_head, av, ac);
	check_double(&a_head);
	i = len(a_head);
	if (i < 4)
		therd_algo(&a_head, &b_head, av, ac);
	else if (i < 6)
		second_algo(&a_head, &b_head, av, ac);
	else if (i < 101)
	{
		i = firs_algo(a_head, b_head, av, 0);
		creat(&a_tmp, &b_tmp, av, ac);
		if (i > 700)
			i = firs_algo(a_tmp, b_tmp, av, -1);
		else
			i = firs_algo(a_tmp, b_tmp, av, -2);
	}
	else
	{
		i = firs_algo(a_head, b_head, av, 0);
		creat(&a_tmp, &b_tmp, av, ac);
		if (i > 5500)
			i = firs_algo(a_tmp, b_tmp, av, -1);
		else
			i = firs_algo(a_tmp, b_tmp, av, -2);
	}
	return (0);
}
