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
	t_stack	*mark_head_2;
	int		i;
	int		i2;
	int		k;

	i = 0;
	i2 = 0;
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
	swap(a_head, NULL, 1);
	head = *a_head;
	while (*a_head)
	{
		k = will_stay(head, *a_head);
		if (k > i2)
		{
			i2 = k;
			mark_head_2 = *a_head;
		}
		*a_head = (*a_head)->next;
	}
	*a_head = head;
	if (i > i2)
	{
		swap(a_head, NULL, 1);
		return (mark_head);
	}
	return (mark_head_2);
}

void	mark(t_stack **a_head, t_stack	*mark_head)
{
	t_stack	*head;
	int		tmp;
	int		i;

	i = 0;
	head = *a_head;
	while (head != mark_head)
	{
		head = head->next;
		i++;
	}
	tmp = mark_head->content;
	head->true = 1;
	head = head->next;
	while (head)
	{
		if (head->content > tmp)
		{
			head->true = 1;
			tmp = head->content;
		}
		head = head->next;
	}
	head = *a_head;
	if (*a_head != mark_head)
	{
		while (i)
		{
			if (head->content > tmp)
			{
				head->true = 1;
				tmp = head->content;
			}
			head = head->next;
			i--;
		}
	}
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

void	sort_from_b_to_a(t_stack **a_head, t_stack **b_head)
{
	int		i;
	t_stack	*first;

	while (*b_head)
	{
		first = *b_head;
		if ((*b_head)->next)
			first = whos_first(*a_head, *b_head);
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

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*mark_head;
	int	i;
	int	sw;
	int	k;

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
	printf("%d\n", mark_head->content);
	mark(&a_head, mark_head);
	push_to_b(&a_head, &b_head);
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
