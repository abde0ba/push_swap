/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:45:50 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 13:54:34 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->index = 1;
	tmp->next = *a;
	tmp->index = 0;
	*a = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	(*b)->index = 1;
	tmp->next = *b;
	tmp->index = 0;
	*b = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_lstsize(*b) < 1)
		return ;
	tmp = *b;
	if ((*b))
		*b = (*b)->next;
	if (tmp)
		tmp->next = *a;
	*a = tmp;
	tmp = *a;
	indexing(tmp);
	tmp = *b;
	indexing(tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	indexing(tmp);
	tmp = *a;
	indexing(tmp);
}
