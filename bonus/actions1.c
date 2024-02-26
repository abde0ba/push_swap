/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:25:43 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 12:06:34 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = ft_lstlast(*a);
	last->next = tmp;
	tmp->next = NULL;
	tmp = *a;
	indexing(tmp);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = ft_lstlast(*b);
	last->next = tmp;
	tmp->next = NULL;
	tmp = *b;
	indexing(tmp);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*a) < 2)
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
}
