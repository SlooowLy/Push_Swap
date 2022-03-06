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

int	f_u_25_line(t_stack *a_head, t_stack *b_head, t_op *op, t_25_line_2 *t)
{
	t_stack	*tmp;

	tmp = a_head;
	t->b = b_head->content;
	op->a = 0;
	while (tmp)
	{
		if (t->b < tmp->content && tmp->content == get_min(a_head))
			break ;
		if (tmp == a_head && check_first_last(a_head, t->b))
			break ;
		if (tmp != a_head)
			if (t->t < t->b && t->b < tmp->content)
				break ;
		t->t = tmp->content;
		op->a += 1;
		tmp = tmp->next;
	}
	return (get_op_2(t->lena, t->lenb, op));
}

t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int operations)
{
	t_25_line_2	t;
	t_stack		*first;
	t_op		ret;

	get_default(&t, op, a_head, b_head);
	while (b_head)
	{
		t.r = f_u_25_line(a_head, b_head, op, &t);
		if (t.k > t.r)
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
	t_stack	*tmp_first;
	t_stack	*tmp;
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

int	check_double(t_stack *a_head)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a_head;
	while (tmp)
	{
		i = tmp->content;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->content == i)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_done(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		i;

	i = 0;
	if (*a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free (*a);
			*a = tmp;
		}
	}
	if (*b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free (*b);
			*b = tmp;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	int		i;

	if (ac <= 1)
		exit (1);
	creat(&a_head, &b_head, av, ac);
	if (how_is_it(a_head))
	{
		ft_done(&a_head, &b_head);
		exit (1);
	}
	if (!check_double(a_head))
	{
		while (a_head)
		{
			b_head = a_head->next;
			free(a_head);
			a_head = b_head;
		}
		write (2, "Error\n", 6);
		exit (1);
	}
	i = len(a_head);
	if (i < 4)
		therd_algo(&a_head, &b_head, av, ac);
	else if (i < 6)
		second_algo(&a_head, &b_head, av, ac);
	else
		norm_function(&a_head, &b_head, av, ac);
	system("leaks push_swap");
	return (0);
}
