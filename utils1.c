#include "push_swap_lib.h"

static int	ft_second(const char *a, int r, int i)
{
	int	p;

	p = 0;
	while (i - r != 0)
	{
		p = p * 10 + a[r++] - 48;
	}
	return (p);
}

static int	lenq(const char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	r;

	j = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		j = -1;
		i++;
	}
	if (lenq (str, i) > 10 && j == 1)
		return (0);
	if (lenq (str, i) > 10 && j == -1)
		return (-1);
	r = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (ft_second(str, r, i) * j);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (a == 0)
		return (0);
	a->content = content;
	a->true = 0;
	a->next = NULL;
	return (a);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*a;

	a = *lst;
	if (a)
	{	
		while (a->next != NULL)
			a = a->next;
		a->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
