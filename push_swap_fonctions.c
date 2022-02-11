#include "push_swap_lib.h"

int	checker(int	swap, t_stack **a_head, t_stack **b_head)
{
	int	i;

	i = 0;
	if (swap == 1 && *a_head)
	{
		if ((*a_head)->next)
			return (1);
		return (0);
	}
	if (swap == 2 && *b_head)
	{
		if ((*b_head)->next)
			return (1);
		return (0);
	}
	if (swap == 3 && *a_head && *b_head)
	{
		if ((*a_head)->next && (*b_head)->next)
			return (1);
		return (0);
	}
	if (swap == 4 || swap == 7 || swap == 10)
	{
		if (*b_head)
			return (1);
		return (0);
	}
	if (swap == 5 || swap == 6 || swap == 9)
	{
		if (*a_head)
			return (1);
		return (0);
	}
	if (swap == 8 || swap == 11)
	{
		if (*a_head && *b_head)
			return (1);
		return (0);
	}
	return (0);
}

void	swap(t_stack **a_head, t_stack **b_head, int swap)
{
	int	temp;
	t_stack	*tm;
	t_stack	*tm2;

	if (checker(swap, a_head, b_head) && (swap == 1 || swap == 3))
	{
		tm = *a_head;
		temp = tm->content;
		tm = tm->next;
		(*a_head)->content = tm->content;
		tm->content = temp;
		if (swap == 1)
			printf ("sa\n");
	}
	if (checker(swap, a_head, b_head) &&(swap == 2 || swap == 3))
	{
		tm = *b_head;
		temp = tm->content;
		tm = tm->next;
		(*b_head)->content = tm->content;
		tm->content = temp;
		if (swap == 2)
			printf ("sb\n");
	}
	if (checker(swap, a_head, b_head) && (swap == 4))
	{
		if (a_head)
		{
			tm = *b_head;
			ft_lstadd_front(a_head, ft_lstnew(tm->content));
			tm = tm->next;
			free (*b_head);
			// *b_head = NULL;
			*b_head = tm;
		}
		else
			*a_head = ft_lstnew((*b_head)->content);
		printf ("pa\n");
	}
	if (checker(swap, a_head, b_head) && (swap == 5))
	{
		if (*b_head)
		{
			tm = *a_head;
			ft_lstadd_front(b_head, ft_lstnew(tm->content));
			tm = tm->next;
			free (*a_head);
			// *a_head = NULL;
			*a_head = tm;
		}
		else
		{
			*b_head = ft_lstnew((*a_head)->content);
			tm = *a_head;
			tm = tm->next;
			free (*a_head);
			// *a_head = NULL;
			*a_head = tm;
		}
		printf ("pb\n");
	}
	if (checker(swap, a_head, b_head) && (swap == 6 || swap == 8))
	{
		tm = *a_head;
		while (tm->next)
			tm = tm->next;
		tm->next = *a_head;
		tm2 = (*a_head)->next;
		(*a_head)->next = NULL;
		*a_head = tm2;
	}
	if (checker(swap, a_head, b_head) && (swap == 7 || swap == 8))
	{
		tm = *b_head;
		while (tm->next)
			tm = tm->next;
		tm->next = *b_head;
		tm2 = (*b_head)->next;
		(*b_head)->next = NULL;
		*b_head = tm2;
	}
	if (checker(swap, a_head, b_head) && (swap == 9 || swap == 11))
	{
		tm = *a_head;
		tm2 = *a_head;
		while (tm->next)
		{
			tm2 = tm;
			tm = tm->next;
		}
		tm->next = *a_head;
		*a_head = tm;
		tm2->next = NULL;
		printf ("rra\n");
	}
	if (checker(swap, a_head, b_head) && (swap == 10 || swap == 11))
	{
		tm = *b_head;
		tm2 = *b_head;
		while (tm->next)
		{
			tm2 = tm;
			tm = tm->next;
		}
		tm->next = *b_head;
		*b_head = tm;
		tm2->next = NULL;
		if (swap == 10)
			printf ("rrb\n");
	}
}