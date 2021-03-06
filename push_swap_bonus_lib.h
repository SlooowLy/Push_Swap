/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_lib.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:50:47 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/06 10:50:48 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_LIB_H
# define PUSH_SWAP_BONUS_LIB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 1

typedef struct s_stack
{
	int				content;
	int				true;
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
	int	*operations;
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

int			creat(t_stack **a_head, t_stack **b_head, char **av, int ac);
int			cpy_next_line(char **all, int fd);
int			check_next_ln(char *all);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
int			new_line_index(char	*all);
int			len(char *str);
char		*ft_return(char *all, int i);
char		*edit_all(char *all, int i, int k);
int			swap_5(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap_8(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap_4(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap_3(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap_7(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap_6(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap_2(t_stack **a_head, t_stack **b_head, int swap, int o);
int			swap(t_stack **a_head, t_stack **b_head, int swap, int o);
int			how_is_it(t_stack *a_head);
t_stack		*ft_lstnew(int content);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
long int	ft_atoi(const char *str);
int			checker(int swap, t_stack **a_head, t_stack **b_head);
char		**ft_split(char const *s, char c);
int			check_safety(char *str);
void		second_creat(char **av2, t_stack **a_head, int k);
void		ft_free(t_stack **a_head, char ***av);
int			check_double(t_stack *a_head);
char		**first_creat(char **av, char **av2, t_stack **a_head);
void		check_split(char const *s);
void		print_resault(t_stack *a_head);

#endif
