#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <stdio.h>
# include <unistd.h>
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
	int	operations;
}	t_op;

typedef struct s_25_line
{
	int		min;
	t_op	op;
}	t_25_line;

typedef struct s_25_line_2
{
	int		k;
	int		b;
	int		t;
	int		r;
	int		lenb;
	int		lena;
}	t_25_line_2;

typedef struct s_ints
{
	int	operations;
	int	swap;
}	t_ints;

t_stack	*ft_lstnew(int content);
long int	ft_atoi(const char *str);
int		checker(int swap, t_stack **a_head, t_stack **b_head);
int		checker_2(int swap, t_stack **a_head, t_stack **b_head);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int	swap(t_stack **a_head, t_stack **b_head, int swap, int operations);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_free(t_stack **a_head, char ***av);
int	swap_5(t_stack **a_head, t_stack **b_head, int swap, int operations);
int	swap_8(t_stack **a_head, t_stack **b_head, int swap, int operations);
int	swap_4(t_stack **a_head, t_stack **b_head, int swap, int operations);
int	swap_3(t_stack **a_head, t_stack **b_head, int swap, int operations);
int	swap_7(t_stack **a_head, t_stack **b_head, int swap, int operations);
int	swap_6(t_stack **a_head, t_stack **b_head, int swap, int operations);
int	swap_2(t_stack **a_head, t_stack **b_head, int swap, int operations);
void	mark(t_stack **a_head, t_stack **b_head, t_stack *mark_head);
t_stack	*get_mark_head(t_stack **a_head);
int		get_i_1(t_op *op, int lena, int lenb, int i);
int		how_is_it(t_stack *a_head);
int		creat(t_stack **a_head, t_stack **b_head, char **av, int ac);
int	last_swap(t_stack **a_head, int operations);
int		len(t_stack *head);
int		get_i_2(t_op *op, int lena, int lenb, int i);
int	check_first_last(t_stack *a_head, int b);
int	get_min(t_stack	*a_head);
int	push_to_b(t_stack **a_head, t_stack **b_head, int operations);
int	check_push_b(t_stack *a_head);
int	get_max(t_stack *a_head);
int	will_stay(t_stack *a_head, t_stack *head, int i, int tmp);
int	check_a(t_stack *a_head, t_stack *first, int min);
int	get_min_place(t_stack *a_head);
int	sort_from_b_to_a(t_stack **a_head, t_stack **b_head, int operations);
t_stack	*whos_first(t_stack *a_head, t_stack *b_head, t_op *op, int operations);
int	swap_b_a(t_stack **a_head, t_stack **b_head, t_stack *first, t_op *op);
int		check_b_a(t_stack *a_head, t_stack *b_head, t_stack *first, int min);
int		check_b(t_stack *b_head, t_stack *first);
int		get_min_2(t_stack *a_head, t_stack *b_head);
int		get_len(double	ln);
char	**ft_split(char const *s, char c);
void	second_creat(char **av2, t_stack **a_head, int k);
char	**first_creat(char **av, char **av2, t_stack **a_head);
void	second_algo(t_stack **a_head, t_stack **b_head, char **av, int ac);
void	therd_algo(t_stack **a_head, t_stack **b_head, char **av, int ac);
void	norm_function(t_stack *a, t_stack *b, char **av, int ac);
int	get_op_2(int lena, int lenb, t_op *op);
void	get_default(t_25_line_2 *t, t_op *op, t_stack *a_head, t_stack *b_head);
int		print_op(int swap, int operations);
void	ft_done(t_stack **a, t_stack **b);
void	print_the_stack(t_stack *stack);
void	ft_done(t_stack **a, t_stack **b);
void	ft_done_2(t_stack **h);
int	check_double(t_stack *a_head);

# endif