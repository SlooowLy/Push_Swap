#include "push_swap_lib.h"

// void	print_the_stack(t_stack *stack)
// {
// 	printf ("%d ", stack->content);
// 	while (stack->next)
// 	{
// 		stack = stack->next;
// 		printf ("%d ", stack->content);
// 	}
// }

int	op_number(t_op *op, int lena, int lenb)
{
	int	i;
	int	j;
	int	k;
	int	a;
	int	b;

	i = 100000;
	if (op->oa == 0 && op->ob == 0)
		i = 0;
	if (op->oa == 0 && op->ob == 1)
		i = (lenb - op->b) + 1;
	if (op->oa == 0 && op->ob == 2)
		i = op->b;
	if (op->oa == 1 && op->ob == 0)
		i = (lena - op->a) + 1;
	if (op->oa == 1 && op->ob == 1)
	{
		i = (lenb - op->b) + 1;
		if (i < (lena - op->a) + 1)
			i = (lena - op->a) + 1;
	}
	if (op->oa == 1 && op->ob == 2)
	{
		a = (lena - op->a) + 1;
		b = (lenb - op->b) + 1;
		j = a;
		if (j < b)
			j = b;
		k = op->b;
		if (k < op->a)
			k = op->a;
		if (k < i)
			i = k;
		if (j < i)
			i = j;
		if (i > (lena - op->a) + 1 + op->b)
			i = (lena - op->a) + 1 + op->b;
	}
	if (op->oa == 2 && op->ob == 0)
		i = op->a;
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
		if (k < i)
			i = k;
		if (j < i)
			i = j;
		if (i > ((lenb - op->b) + 1) + op->a)
			i = ((lenb - op->b) + 1) + op->a;
	}
	if (op->oa == 2 && op->ob == 2)
	{
		if (op->a <= op->b)
			i = op->b;
		if (op->a > op->b)
			i = op->a;
	}
	return (i);
}

t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int min)
{
	int		i;
	int		k;
	int		k1;
	int		b;
	int		t;
	int		r;
	int		lenb;
	int		lena;
	t_stack	*first;
	t_stack *tmp;
	t_op	ret;

	op->b = 0;
	op->a = 0;
	k = 1000000;
	lena = len(a_head);
	lenb = len(b_head);
	while (b_head)
	{
		tmp = a_head;
		b = b_head->content;
		op->a = 0;
		while (tmp)
		{
			if (b < tmp->content && tmp->content == get_min(a_head))
				break;
			if (tmp == a_head && check_first_last(a_head, b))
				break;
			if (tmp != a_head)
			{
				if (t < b && b < tmp->content)
					break;
				if (b > t && t == get_max(a_head))
					break;
			}
			t = tmp->content;
			op->a += 1;
			tmp = tmp->next;
		}
		get_op(lena, lenb, op);
		r = op_number(op, lena, lenb);
		if (k > r)
		{
			ret = *op;
			first = b_head;
			k = r;
		}
		op->b += + 1;
		b_head = b_head->next;
	}
	*op = ret;
	return (first);
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*mark_head;
	int		i;

	creat(&a_head, &b_head, av, ac);
	mark_head = get_mark_head(&a_head);
	mark(&a_head, &b_head, mark_head);
	i = get_min(a_head);
	push_to_b(&a_head, &b_head);
	sort_from_b_to_a(&a_head, &b_head, i);
	last_swap(&a_head);
	// while (1)
	// {
	// 	i = 1;
	// }
	// printf ("a ");
	// print_the_stack(a_head);
	return (0);
}
