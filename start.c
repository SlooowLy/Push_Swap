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

t_stack	*get_mark_head(t_stack *a_head)
{
	t_stack	*temp;
	t_stack	*mark_head;
	int		i;
	int		k;

	i = 0;
	temp = a_head;
	while (a_head)
	{
		k = will_stay(temp, a_head);
		if (k > i)
		{
			i = k;
			mark_head = a_head;
		}
		a_head = a_head->next;
	}
	return (mark_head);
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

t_stack	*push_to_b(t_stack **a_head, t_stack **b_head)
{

	while (check_push_b(*a_head))
	{
		if ((a_head)->)
			swap(a_head, b_head, 5);
	}
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
		// ft_lstadd_back(&b_head, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
	mark_head = get_mark_head(a_head);
	mark(&a_head, mark_head);
	// swap(&a_head, &b_head, sw);
	// printf ("a ");
	// print_the_stack(a_head);
	// printf ("\nb ");
	// print_the_stack(b_head);
	return (0);
}
