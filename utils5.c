/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:43 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/12 22:44:21 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	tmp = *a;
	*a = (*a)->next;
	last = ft_lstlast(*a);
	last->next = tmp;
	tmp->next = NULL;
	tmp = *a;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	tmp = *b;
	*b = (*b)->next;
	last = ft_lstlast(*b);
	last->next = tmp;
	tmp->next = NULL;
	tmp = *b;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	tmp = *a;
	if (ft_lstiter(*a) < 2)
		return ;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	tmp = *a;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	tmp = *b;
	if (ft_lstiter(*b) < 2)
		return ;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	tmp = *b;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	write(1, "rrb\n", 4);
}
