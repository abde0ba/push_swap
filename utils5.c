/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:43 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/17 14:48:45 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *tmp)
{
	int		index;

	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
}

void	ra(t_stack **a, int display)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	if (ft_lstiter(*a) < 2)
		return ;
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
	if (display)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int display)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;


	if (ft_lstiter(*b) < 2)
		return ;
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
	if (display)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_stack **a, int display)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstiter(*a) < 2)
		return ;
	tmp = *a;
	while (tmp)
	{
		if (tmp->next->next == NULL)
			break ;
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	tmp = *a;
	indexing(tmp);
	if (display)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int display)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	if (ft_lstiter(*b) < 2)
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
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	if (display)
		write(1, "rrb\n", 4);
}
