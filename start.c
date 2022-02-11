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

void	sort_b(t_stack **a_head, t_stack **b_head)
{
	int	j;
	int	k;

	j = compaire(*a_head, *b_head, 3);
	k = compaire(*a_head, *b_head, 3);
	if (k > j)
	{
		swap(a_head, b_head, 2);
		// printf ("2\n");
	}
	if (j > k)
	{
		swap(a_head, b_head, 10);
		// printf ("10\n");
	}
	if (k == j && k)
	{
		swap(a_head, b_head, 2);
		// printf ("2\n");
	}
}

void	push_swap(t_stack **a_head, t_stack **b_head, int ac)
{
	int	i;
	int	j;
	int	k;
	int	sp;

	i = 0;
	while (!(how_is_it(*a_head, *b_head, 1)))
	{
		k = compaire(*a_head, *b_head, 1);
		j = compaire(*a_head, *b_head, 2);
		if (k > j)
		{
			swap(a_head, b_head, 1);
			// printf ("1\n");
		}
		if (j > k)
		{
			swap(a_head, b_head, 9);
			// printf ("9\n");
		}
		if (k == j && k)
		{
			swap(a_head, b_head, 1);
			// printf ("1\n");
		}
		if (k == 0 && j == 0)
		{
			swap(a_head, b_head, 5);
			sort_b(a_head, b_head);
			// printf ("5\n");
		}
		while (how_is_it(*a_head, *b_head, 1) && *b_head)
		{
			sort_b(a_head, b_head);
			swap(a_head, b_head, 4);
			// printf ("4\n");
		}
	}
	// while (*b_head)
	// {
	// 	sort_b(a_head, b_head);
	// 	swap(a_head, b_head, 4);
	// 	printf ("pa\n");
	// }
}

int	main(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*b_head;
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
		// ft_lstadd_back(&b_head, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
	push_swap(&a_head, &b_head, ac);
	// swap(&a_head, &b_head, sw);
	// printf ("a ");
	// print_the_stack(a_head);
	// printf ("\nb ");
	// print_the_stack(b_head);
	return (0);
}
