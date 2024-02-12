/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:45:50 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/12 22:23:29 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->index = 1;
	tmp->next = *a;
	tmp->index = 0;
	*a = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	(*b)->index = 1;
	tmp->next = *b;
	tmp->index = 0;
	*b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		index;

	tmp = *b;
	if ((*b))
		*b = (*b)->next;
	if (tmp)
		tmp->next = *a;
	*a = tmp;
	index = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		index;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	index = 0;
	*b = tmp;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	tmp = *a;
	write(1, "pb\n", 3);
}
