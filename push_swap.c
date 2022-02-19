#include "push_swap_lib.h"

int	how_is_it(t_stack *a_head)
{
	int	i;
	t_stack *the_next;

	i = 0;
	while (a_head->next)
	{
		the_next = a_head->next;
		if (the_next->content < a_head->content)
			return (0);
		a_head = the_next;
	}
	return (1);
}

void	print_the_stack(t_stack *stack)
{
	printf ("%d ", stack->content);
	while (stack->next)
	{
		stack = stack->next;
		printf ("%d ", stack->content);
	}
}

int	compaire(t_stack *a_head, t_stack *b_head, int cm)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (cm == 1)
	{
		temp = a_head->next;
		if (temp)
		{
			if (a_head->content > temp->content)
				return (a_head->content - temp->content);
		}
	}
	if (cm == 2)
	{
		temp = a_head;
		while (temp->next)
			temp = temp->next;
		if (a_head->content > temp->content)
			return (a_head->content - temp->content);
	}
	if (cm == 3)
	{
		temp = b_head->next;
		if (temp)
		{
			if (b_head->content < temp->content)
				return (-1 * (b_head->content - temp->content));
		}
	}
	if (cm == 4)
	{
		temp = b_head;
		while (temp->next)
			temp = temp->next;
		if (b_head->content < temp->content)
			return (-1 * (b_head->content - temp->content));
	}
	return (0);
}

int	will_stay(t_stack *a_head, t_stack *head)
{
	int	i;
	int	tmp;
	t_stack	*temp;

	temp = head;
	i = 1;
	tmp = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (temp->content > tmp)
		{
			i++;
			tmp = temp->content;
		}
		temp = temp->next;
	}
	while (head != a_head)
	{
		if (a_head->content > tmp)
		{
			i++;
			tmp = a_head->content;
		}
		a_head = a_head->next;
	}
	return (i);
}

t_stack	*get_mark_head(t_stack **a_head)
{
	t_stack	*head;
	t_stack	*mark_head;
	int		i;
	int		k;

	i = 0;
	head = *a_head;
	while (*a_head)
	{
		k = will_stay(head, *a_head);
		if (k > i || (k == i && mark_head->content < (*a_head)->content))
		{
			i = k;
			mark_head = *a_head;
		}
		*a_head = (*a_head)->next;
	}
	*a_head = head;
	return (mark_head);
}

void	mark_2(t_stack **a_head, t_stack **b_head, t_stack *head)
{
	t_stack	*tmp;
	t_stack	*first_tmp;

	first_tmp = *a_head;
	tmp = (*a_head)->next;
	*a_head = (*a_head)->next->next;
	while (*a_head)
	{
		if (!(*a_head)->true && (*a_head)->content < first_tmp->content && tmp->true)
		{
			(*a_head)->true = 1;
			first_tmp = *a_head;
		}
		else
			tmp = *a_head;
		*a_head = (*a_head)->next;
	}
}

void	mark(t_stack **a_head, t_stack **b_head, t_stack *mark_head)
{
	t_stack	*tmp;
	t_stack	*head;

	while (*a_head != mark_head)
		swap(a_head, NULL, 9);
	(*a_head)->true = 1;
	tmp = *a_head;
	*a_head = (*a_head)->next;
	while (*a_head)
	{
		if ((*a_head)->content > tmp->content)
		{
			(*a_head)->true = 1;
			tmp = *a_head;
		}
		*a_head = (*a_head)->next;
	}
	*a_head = mark_head;
	// mark_2(a_head, b_head, mark_head);
	*a_head = mark_head;
}

int	check_push_b(t_stack *a_head)
{
	while (a_head)
	{
		if (a_head->true == 0)
			return (1);
		a_head = a_head->next;
	}
	return(0);
}

void	push_to_b(t_stack **a_head, t_stack **b_head)
{

	while (check_push_b(*a_head))
	{
		if ((*a_head)->true == 0)
		{
			swap(a_head, b_head, 5);
		}
		else
			swap(a_head, b_head, 6);
	}
}

int	check_last_content(t_stack *a_head, int b)
{
	while (a_head->next)
		a_head = a_head->next;
	if (a_head->content < b)
		return (1);
	return (0);
}

int	check_all_content(t_stack *a_head, int b)
{
	while (a_head)
	{
		if (a_head->content < b)
			return (0);
		a_head = a_head->next;
	}
	return (1);
}

int	get_min(t_stack	*a_head)
{
	int	tmp;

	tmp = a_head->content;
	while (a_head)
	{
		if (a_head->content < tmp)
			tmp = a_head->content;
		a_head = a_head->next;
	}
	return (tmp);
}

int	check_first_last(t_stack *a_head, int b)
{
	t_stack	*tmp;

	tmp = a_head;
	while (tmp->next)
		tmp = tmp->next;
	if (a_head->content > b && tmp->content < b)
		return (1);
	return (0);
}

int	len(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	compaire_to_all(t_stack *head, int b)
{
	while (head)
	{
		if (head->content < b)
			return (0);
		head = head->next;
	}
	return (1);
}

void	get_op(int	lena, int lenb, t_op *op)
{
	if (op->b == 0)
		op->ob = 0;
	if (op->a == 0)
		op->oa = 0;
	if (op->b >= lenb / 2)
		op->ob = 1;
	else
		op->ob = 2;
	if (op->a >= lena / 2)
		op->oa = 1;
	else
		op->oa = 2;
	op->o = 0;
}

int	check_1_2(t_op *op, int i, t_stack *a_head, t_stack *b_head)
{
	int	j;
	int	k;
	int	a;
	int	b;

	if (op->oa == 1 && op->ob == 2)
	{
		b = len(b_head) - op->b;
		a = len(a_head) - op->a;
		j = a;
		if (j < b)
			j = b;
		k = op->b;
		if (k < op->a)
			k = op->a;
		if (k < i)
		{
			op->o = 4;
			i = k;
		}
		if (j < i)
		{
			op->o = 3;
			i = j;
		}
		if (i > ((len(a_head) - op->a) + 1) + op->b)
		{
			op->o = 0;
			i = ((len(a_head) - op->a) + 1) + op->b;
		}
	}
	if (op->oa == 2 && op->ob == 1)
	{
		a = len(a_head) - op->a;
		b = len(b_head) - op->b;
		j = a;
		if (j < b)
			j = b;
		k = op->b;
		if (k < op->a)
			k = op->a;
		if (k < i)
		{
			op->o = 4;
			i = k;
		}
		if (j < i)
		{
			op->o = 3;
			i = j;
		}
		if (i > ((len(b_head) - op->b) + 1) + op->a)
		{
			op->o = 0;
			i = ((len(b_head) - op->b) + 1) + op->a;
		}
	}
	return (op->o);
}

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

int	get_max(t_stack *a_head)
{
	int	i;

	i = a_head->content;
	while (a_head)
	{
		if (i < a_head->content)
			i = a_head->content;
		a_head = a_head->next;
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

int	check_b_a(t_stack *a_head, t_stack *b_head, t_stack *first, int min)
{
	t_stack	*tmp;

	tmp = a_head;
	if (b_head != first)
		return (0);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (first->content > tmp->content && first->content < a_head->content)
			return (1);
		else if ((first->content == min || first->content < get_min (a_head)) && a_head->content == get_min(a_head))
			return (1);
		else if ((first->content < a_head->content && a_head->content == get_min(a_head)))
			return (1);
	}
	return (0);
}

int	check_b(t_stack *b_head, t_stack *first)
{
	if (b_head != first)
		return (0);
	return(1);
}

int	check_a(t_stack *a_head, t_stack *first, int min)
{
	t_stack	*tmp;

	tmp = a_head;
	while (tmp->next)
			tmp = tmp->next;
	if (first->content > tmp->content && first->content < a_head->content)
		return (1);
	else if (first->content < a_head->content && a_head->content == get_min(a_head))
		return (1);
	else if (first->content > tmp->content && tmp->content == get_max(a_head))
		return (1);
	return(0);
}

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

void	sort_from_b_to_a(t_stack **a_head, t_stack **b_head, int min)
{
	int		i;
	t_op	op;
	t_stack	*first;

	i = 0;
	while (*b_head)
	{
		first = *b_head;
		if ((*b_head)->next)
			first = whos_first(*a_head, *b_head, &op, min);
		swap_b_a(a_head, b_head, first, &op, min);
	}
}

int	get_min_place(t_stack *a_head)
{
	int	i;
	int	k;

	i = 0;
	k = get_min(a_head);
	while (k != a_head->content)
	{
		i++;
		a_head = a_head->next;
	}
	return (i);
}

int	check_sort(t_stack *a_head)
{
	t_stack	*tmp;
	t_stack	*head;

	head = a_head;
	while (a_head)
	{
		if (a_head->next)
		{
			if (a_head->content > a_head->next->content && a_head->next->content != get_min(a_head))
				return (0);
		}
		else
		{
			tmp = head;
			if (a_head->content > tmp->content && tmp->content != get_min(a_head))
				return (0);
		}
		a_head = a_head->next;
	}
	return (1);
}

void	swap_to_head_sa(t_stack **a_head, t_stack *tmp)
{
	if ((*a_head)->next)
	{
		if (*a_head != tmp)
		{
			while (*a_head != tmp)
				swap(a_head, NULL, 6);
		}
	}
	else
		swap(a_head, NULL, 9);
	swap(a_head, NULL, 1);
}

void	sort_in_a(t_stack **a_head, t_stack *mark_head)
{
	t_stack	*min;
	t_stack	*tmp;
	t_stack	*head;

	mark_head->true = 1;
	(*a_head)->true = 1;
	head = *a_head;
	tmp = *a_head;
	*a_head = (*a_head)->next;
	while ((*a_head)->content != mark_head->content)
	{
		if ((*a_head)->content < tmp->content)
		{
			*a_head = head;
			while (*a_head != tmp)
				swap (a_head, NULL, 6);
			swap (a_head, NULL, 1);
			head = *a_head;
		}
		tmp = *a_head;
		*a_head = (*a_head)->next;
		if (*a_head == NULL)
			break;
	}
	*a_head = head;
}

void last_swap(t_stack **a_head)
{
	int	i;
	int	k;

	i = get_min_place(*a_head);
	k = len(*a_head);
	while (!how_is_it(*a_head))
	{
		if (i < k / 2)
			swap(a_head, NULL, 6);
		else
			swap(a_head, NULL, 9);
	}
}

void	creat(t_stack **a_head, t_stack **b_head, char **av, int ac)
{
	int	i;

	i = 1;
	*a_head = ft_lstnew(ft_atoi(av[1]));
	*b_head = NULL;
	while (i < ac - 1)
	{
		ft_lstadd_back(a_head, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
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
