#include "push_swap_lib.h"

// 1 sa
// 2 sb
// 3 ss
// 4 pa
// 5 pb
// 6 ra
// 7 rb
// 9 rra
// 10 rrb

int	how_is_it(t_stack *a_head, t_stack *b_head, int sw)
{
	int	i;
	t_stack *the_next;

	i = 0;
	if (sw == 1 && a_head)
	{
		while (a_head->next)
		{
			the_next = a_head->next;
			if (the_next->content < a_head->content)
				return (0);
			a_head = the_next;
		}
	}
	if (sw == 2 && b_head)
	{
		while (b_head->next)
		{
			the_next = b_head->next;
			if (the_next->content > b_head->content)
				return (0);
			b_head = the_next;
		}
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
		// printf ("%d\n", k);
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
	mark_2(a_head, b_head, mark_head);
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
			swap(a_head, b_head, 5);
		else
		{
			swap(a_head, b_head, 6);
		}
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
	int		i;
	t_stack	*tmp;

	tmp = a_head;
	i = 0;
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

t_stack	*whos_first(t_stack *a_head, t_stack *b_head)
{
	int		i;
	int		k;
	int		k1;
	int		b;
	int		t;
	int		r;
	t_stack	*first;
	t_stack *tmp;

	k = 0;
	r = 0;
	while (b_head)
	{
		tmp = a_head;
		b = b_head->content;
		i = 0;
		while (tmp)
		{
			if (tmp == a_head && check_first_last(a_head, b))
				break;
			if (tmp != a_head)
			{
				if (t < b && b < tmp->content)
				{
					break;
				}
			}
			t = tmp->content;
			i++;
			tmp = tmp->next;
		}
		if (i > len(a_head))
			i = len(a_head) - i;
		if (k > len(b_head))
			k = len(b_head) - k;
		if (r > i + k || !r)
		{
			first = b_head;
			r = i + k;
		}
		k++;
		b_head = b_head->next;
	}
	return (first);
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

t_op	get_op(t_stack *a_head, t_stack *b_head, t_stack *first)
{
	t_op	op;
	t_stack	*tmp;

	tmp = b_head;
	op.a = 0;
	op.b = 0;
	while (tmp != first)
	{
		tmp = tmp->next;
		op.b++;
	}
	tmp = a_head;
	while (!check_first_last(tmp, first->content))
	{
		tmp = tmp->next;
		op.a++;
	}
	if (op.b == 0 && op.a == 0)
	{
		op.oa = 0;
		op.ob = 0;
		return (op);
	}
	if (op.b > len(b_head) / 2)
		op.b = len(b_head) - op.b + 1;
	else
		op.b *= -1;
	if (op.a > len(a_head) / 2)
		op.a = len(a_head) - op.a + 1;
	else
		op.a *= -1;
	if (op.a > 0)
		op.oa = 1;
	if (op.a < 0)
		op.oa = 2;
	if (op.b > 0)
		op.ob = 1;
	if (op.b < 0)
		op.ob = 2;
	return (op);
}

void	sort_from_b_to_a(t_stack **a_head, t_stack **b_head)
{
	int		i;
	// t_op	op;
	t_stack	*first;

	while (*b_head)
	{
		first = *b_head;
		if ((*b_head)->next)
			first = whos_first(*a_head, *b_head);
		// op = get_op(*a_head, *b_head, first)
		while (*b_head != first)
			swap(a_head, b_head, 7);
		while (!check_first_last(*a_head, (*b_head)->content))
		{
			if (get_max(*a_head) < (*b_head)->content || get_min(*a_head) > (*b_head)->content)
			{
				i = get_min(*a_head);
				while ((*a_head)->content != i)
					swap(a_head, b_head, 6);
				break;
			}
			else
			{
				swap(a_head, b_head, 6);
			}
		}
		swap(a_head, b_head, 4);
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
	}
	*a_head = head;
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*tmp;
	t_stack	*mark_head;
	int	i;
	int	sw;
	int	k;
	int	min;

	i = 1;
	sw = 1;
	k = 1;
	a_head = ft_lstnew(ft_atoi(av[1]));
	b_head = NULL;
	while (i < ac - 1)
	{
		ft_lstadd_back(&a_head, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
	mark_head = get_mark_head(&a_head);
	// printf ("%d\n", mark_head->content);
	mark(&a_head, &b_head, mark_head);
	// printf ("%d\n", i);
	min = get_min(a_head);
	push_to_b(&a_head, &b_head);
	// sort_in_a(&a_head, mark_head);
	sort_from_b_to_a(&a_head, &b_head);
	i = get_min_place(a_head);
	k = len(a_head);
	while (!how_is_it(a_head, b_head, 1))
	{
		if (i < k / 2)
			swap(&a_head, &b_head, 6);
		else
			swap(&a_head, &b_head, 9);
	}
	// printf ("a ");
	// print_the_stack(a_head);
	// printf ("\nb ");
	// print_the_stack(b_head);
	return (0);
}
