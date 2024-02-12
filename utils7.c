/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:09:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/12 22:13:32 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value && (*a)->value > (*a)->next->next->value)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->value > (*a)->next->value)
	{
		sa(a);
	}
	else if ((*a)->value > (*a)->next->next->value)
	{
		rra(a);
	}
	else if ((*a)->next->value > (*a)->next->next->value)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		min;

	min = 0;
	current = *a;
	while (current)
	{
		if (check_min(current->value, &current))
		{
			min = current->index;
			break ;
		}
		current = current->next;
	}
	find_min_in_4(min, a, b);
	sort_3(a, b);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		min;

	current = *a;
	min = 0;
	while (current)
	{
		if (check_min(current->value, &current))
		{
			min = current->index;
			break ;
		}
		current = current->next;
	}
	find_min_in_5(min, a, b);
	sort_4(a, b);
	pa(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	if (ft_lstiter(*a) == 2)
		sa(a);
	else if (ft_lstiter(*a) == 3)
		sort_3(a, b);
	else if (ft_lstiter(*a) == 4)
		sort_4(a, b);
	else if (ft_lstiter(*a) == 5)
		sort_5(a, b);
	// else if (ft_lstiter(*a) > 5)
	// 	quicksort(a, b, 100);
}
