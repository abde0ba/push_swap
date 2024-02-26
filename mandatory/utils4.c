/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:02:32 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 15:55:57 by darkab           ###   ########.fr       */
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
	int		size;

	(1) && (i = 0, current = *stack, size = ft_lstsize(*stack),
	sorted = malloc(size * sizeof(int)));
	if (!sorted)
		return (-1);
	while (current)
	{
		sorted[i] = current->value;
		i++;
		current = current->next;
	}
	bubble_sort(sorted, size);
	if (!set)
		i = sorted[size / 4];
	else if (set == 1)
		i = sorted[size - 1];
	else if (set == 2)
		i = sorted[0];
	if (set == 50)
		i = sorted[size / 2];
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

int	*get_min_and_max(t_stack **stack, int *min_and_max)
{
	t_stack	*current;
	int		*sorted;
	int		i;
	int		size;

	sorted = malloc(ft_lstsize(*stack) * sizeof(int));
	if (!sorted)
		return (NULL);
	(1) && (i = 0, current = *stack, size = ft_lstsize(*stack));
	while (current)
	{
		sorted[i] = current->value;
		i++;
		current = current->next;
	}
	bubble_sort(sorted, size);
	min_and_max[0] = sorted[0];
	min_and_max[1] = sorted[size - 1];
	return (free(sorted), min_and_max);
}
