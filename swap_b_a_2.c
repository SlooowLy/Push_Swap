/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b_a_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:16:11 by aaitoual          #+#    #+#             */
/*   Updated: 2022/02/20 19:16:37 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	get_min_2(t_stack *a_head, t_stack *b_head)
{
	int	j;
	int	k;

	j = get_min(a_head);
	k = get_min(b_head);
	if (j < k)
		return (j);
	return (k);
}

int	check_b_a(t_stack *a_head, t_stack *b_head, t_stack *first, int min)
{
	t_stack	*tmp;

	tmp = a_head;
	if (b_head != first)
		return (0);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (first->content > tmp->content && first->content < a_head->content)
			return (1);
		else if ((first->content == min
				|| first->content < get_min (a_head))
			&& a_head->content == get_min(a_head))
			return (1);
		else if ((first->content < a_head->content
				&& a_head->content == get_min(a_head)))
			return (1);
	}
	return (0);
}
