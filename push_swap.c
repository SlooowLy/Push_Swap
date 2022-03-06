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

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	int		i;

	if (ac <= 1)
		exit (1);
	creat(&a_head, &b_head, av, ac);
	if (!check_double(a_head))
		ft_done_2(&a_head);
	if (how_is_it(a_head))
	{
		ft_done(&a_head, &b_head);
		exit (1);
	}
	i = len(a_head);
	if (i < 4)
		therd_algo(&a_head, &b_head, av, ac);
	else if (i < 6)
		second_algo(&a_head, &b_head, av, ac);
	else
		norm_function(NULL, NULL, av, ac);
	return (0);
}
