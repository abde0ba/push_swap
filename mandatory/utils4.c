/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:02:32 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/23 15:49:32 by abbaraka         ###   ########.fr       */
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

int	get_median(t_stack **stack, int set)
{
	t_stack	*current;
	int		*sorted;
	int		i;

	sorted = malloc(ft_lstiter(*stack) * sizeof(int));
	if (!sorted)
		return (-1);
	(1) && (i = 0, current = *stack);
	while (current)
	{
		sorted[i] = current->value;
		i++;
		current = current->next;
	}
	bubble_sort(sorted, ft_lstiter(*stack));
	if (!set)
		i = sorted[ft_lstiter(*stack) / 4];
	else if (set == 1)
		i = sorted[ft_lstiter(*stack) - 1];
	else if (set == 2)
		i = sorted[0];
	if (set == 50)
		i = sorted[ft_lstiter(*stack) / 2];
	return (free(sorted), i);
}

int	get_pos(t_stack **stack, int num)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == num)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

int	check_sub_in_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->sub == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
