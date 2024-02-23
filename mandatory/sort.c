/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:09:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/23 16:45:18 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		ra(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		rra(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
	{
		sa(a);
		ra(a, 1);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		sa(a);
		rra(a, 1);
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
	sort_3(a);
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

void	bubble_sort(int *sorted, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n)
	{
		j = i;
		while (j < n)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_5(a, b);
	else if (ft_lstsize(*a) <= 500)
		best_move(a, b);
}
