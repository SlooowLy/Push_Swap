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
			break ;
		if (t->b > tmp->content && tmp->content == get_max(a_head))
			break;
		if (tmp == a_head && check_first_last(a_head, t->b))
			break ;
		if (tmp != a_head)
		{
			if (t->t < t->b && t->b < tmp->content)
				break ;
			if (t->b > t->t && t->t == get_max(a_head))
				break ;
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

t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int min)
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
		get_op(t.lena, t.lenb, op);
		t.r = op_number(op, t.lena, t.lenb);
		if (t.k > t.r)
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

void	sort_in_a(t_stack **a_head, t_stack *mark_head)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*first_head;
	int		i;
	int		ln;

	head = *a_head;
	tmp = *a_head;
	*a_head = (*a_head)->next;
	ln = len(tmp);
	while (*a_head)
	{
		if ((*a_head)->content < tmp->content && (*a_head)->content != mark_head->content)
		{
			i = get_swap(head, tmp);
			*a_head = head;
			while (*a_head != tmp)
			{
				if (i)
					swap(a_head, NULL, 6);
				else
					swap(a_head, NULL, 9);
			}
			swap(a_head, NULL, 1);
			head = *a_head;
			*a_head = (*a_head)->next;
		}
		tmp = *a_head;
		*a_head = (*a_head)->next;
	}
	*a_head = head;
}

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

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*mark_head;
	int		i;

	creat(&a_head, &b_head, av, ac);
	check_double(&a_head);
	mark_head = get_mark_head(&a_head);
	printf ("%d\n", mark_head->content);
	mark(&a_head, &b_head, mark_head);
	i = get_min(a_head);
	push_to_b(&a_head, &b_head, mark_head);
	// printf ("%d\n", a_head->content);
	// sort_in_a(&a_head, mark_head);
	// sort_from_b_to_a(&a_head, &b_head, i);
	// last_swap(&a_head);
	printf ("a ");
	print_the_stack(a_head);
	return (0);
}
