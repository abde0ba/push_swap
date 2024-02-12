/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:26:39 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/11 15:41:05 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

int	check_min(int num, t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		if (num > current->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	find_min_in_5(int min, t_stack **a, t_stack **b)
{
	if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min == 4)
		rra(a);
	if (!check_sorted(*a))
		return ;
	pb(a, b);
}

void	find_min_in_4(int min, t_stack **a, t_stack **b)
{
	if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
		rra(a);
	pb(a, b);
}
