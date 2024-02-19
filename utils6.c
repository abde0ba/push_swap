/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:26:39 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/17 14:52:56 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
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

int	check_max(int num, t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		if (num < current->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	find_min_in_5(int min, t_stack **a, t_stack **b)
{
	if (min == 1)
		ra(a, 1);
	else if (min == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (min == 4)
		rra(a, 1);
	if (!check_sorted(*a))
		return ;
	pb(a, b);
}

void	find_min_in_4(int min, t_stack **a, t_stack **b)
{
	if (min == 1)
		ra(a, 1);
	else if (min == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min == 3)
		rra(a, 1);
	pb(a, b);
}
void	find_min_in_3(int min, t_stack **a)
{
	if (min == 1)
		ra(a, 1);
	else if (min == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
}