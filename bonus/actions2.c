/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:16:14 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 13:24:14 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	while (tmp)
	{
		if (tmp->next->next == NULL)
			break ;
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	tmp = *b;
	indexing(tmp);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

void	add_to_a(t_stack **a, int num, int index)
{
	t_stack	*new;

	check_double(a, num);
	new = ft_lstnew(num);
	new->index = index;
	if (!new)
	{
		free(new);
		new = NULL;
		return ;
	}
	ft_lstadd_back(a, new);
}
