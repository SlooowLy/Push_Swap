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
	int	o;
	int	oa;
	int	ob;
	int	i;
}	t_op;

typedef struct s_25_line
{
	int		min;
	t_op	op;
}	t_25_line;

t_stack	*ft_lstnew(int content);
int		ft_atoi(const char *str);
int		checker(int swap, t_stack **a_head, t_stack **b_head);
int		checker_2(int swap, t_stack **a_head, t_stack **b_head);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	swap(t_stack **a_head, t_stack **b_head, int swap);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	swap_5(t_stack **a_head, t_stack **b_head, int swap);
void	swap_8(t_stack **a_head, t_stack **b_head, int swap);
void	swap_4(t_stack **a_head, t_stack **b_head, int swap);
void	swap_3(t_stack **a_head, t_stack **b_head, int swap);
void	swap_7(t_stack **a_head, t_stack **b_head, int swap);
void	swap_6(t_stack **a_head, t_stack **b_head, int swap);
void	swap_2(t_stack **a_head, t_stack **b_head, int swap);
void	mark(t_stack **a_head, t_stack **b_head, t_stack *mark_head);
t_stack	*get_mark_head(t_stack **a_head);
int	how_is_it(t_stack *a_head);
void	creat(t_stack **a_head, t_stack **b_head, char **av, int ac);
void last_swap(t_stack **a_head);
int	len(t_stack *head);
int	check_first_last(t_stack *a_head, int b);
int	get_min(t_stack	*a_head);
void	push_to_b(t_stack **a_head, t_stack **b_head);
int	check_push_b(t_stack *a_head);
int	get_max(t_stack *a_head);
int	will_stay(t_stack *a_head, t_stack *head, int i, int tmp);
void	get_op(int	lena, int lenb, t_op *op);
int	check_a(t_stack *a_head, t_stack *first, int min);
int	get_min_place(t_stack *a_head);
void	sort_from_b_to_a(t_stack **a_head, t_stack **b_head, int min);
// t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int min);
t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int min);
void	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op);
// void	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op, int min);
int	check_b_a(t_stack *a_head, t_stack *b_head, t_stack *first, int min);
int	check_1_2(t_op *op, int i, t_stack *a_head, t_stack *b_head);
int	check_b(t_stack *b_head, t_stack *first);

# endif