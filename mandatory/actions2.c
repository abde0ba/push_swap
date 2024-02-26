/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:16:14 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 15:55:05 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b, int display)
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
	if (display)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	loop_in_a(t_stack **a, int *right_pos, int	*pos_in_a, int num)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (current->next && current->value < num && current->next->value > num)
		{
			*right_pos = current->next->value;
			*pos_in_a = current->next->index;
			return ;
		}
		current = current->next;
	}
}
