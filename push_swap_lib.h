#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack
{
	int			content;
	int			true;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op
{
	int	a;
	int	b;
	int	oa;
	int	ob;
	int	i;
}	t_op;


t_stack	*ft_lstnew(int content);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	swap(t_stack **a_head, t_stack **b_head, int swap);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

# endif