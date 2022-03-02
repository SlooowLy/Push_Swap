/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lsts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:52:29 by aaitoual          #+#    #+#             */
/*   Updated: 2022/03/02 15:52:30 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus_lib.h"

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
