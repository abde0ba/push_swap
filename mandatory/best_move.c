/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:57:06 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/24 19:03:05 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_in_a(t_stack **a, int *right_pos, int	*pos_in_a, int num)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (current->next && current->value < num && current->next->value > num)
		{
			*right_pos = current->next->value;
			*pos_in_a = current->next->index;
			return ;
		}
		current = current->next;
	}
}

static int	*best_in_a(t_stack **a, int num, int *arr, int size)
{
	int	value;
	int	actions;
	int	min_and_max[2];
	int	pos;

	(1) && (value = -1, actions = 0, size = ft_lstsize(*a),
	get_min_and_max(a, min_and_max));
	if (size && (num > min_and_max[1] || num < min_and_max[0]))
	{
		value = min_and_max[0];
		pos = get_pos(a, value);
	}
	else if ((*a)->value > num && num > ft_lstlast(*a)->value)
	{
		value = (*a)->value;
		pos = get_pos(a, value);
	}
	else
		loop_in_a(a, &value, &pos, num);
	if (pos <= (size / 2))
		actions += pos;
	else
		actions += size - pos;
	arr[0] = actions;
	arr[1] = value;
	arr[2] = pos;
	return (arr);
}

static void	calc_best(t_stack **a, t_stack **b, int *num)
{
	t_stack	*tmp;
	int		lowest;
	int		actions;
	int		arr[4];
	int		size_b;

	(1) && (size_b = ft_lstsize(*b), lowest = ft_lstsize(*a) + size_b, actions = 0, tmp = *b);
	while (tmp)
	{
		(1) && (best_in_a(a, tmp->value, arr, (lowest - size_b)), actions = arr[0]);
		if (tmp->index <= (size_b / 2))
			actions += tmp->index;
		else
			actions += size_b - tmp->index;
		if (actions < lowest)
		{
			lowest = actions;
			num[0] = tmp->value;
			num[1] = arr[1];
			num[2] = tmp->index;
			num[3] = arr[2];
		}
		tmp = tmp->next;
	}
}

static void	sort_a_and_b(t_stack **a, t_stack **b)
{
	int		num[4];
	int		size_a;
	int		size_b;

	while (*b)
	{
		(1) && (calc_best(a, b, num), size_b = ft_lstsize(*b), size_a = ft_lstsize(*a));
		if ((*b)->value != num[0])
		{
			if (num[2] <= (size_b / 2))
				while ((*b)->value != num[0])
					rb(b, 1);
			else
				while ((*b)->value != num[0])
					rrb(b, 1);
		}
		if (num[3] <= (size_a / 2))
			while ((*a)->value != num[1])
				ra(a, 1);
		else
			while ((*a)->value != num[1])
				rra(a, 1);
		if ((*b)->value == num[0] && (*a)->value == num[1])
			pa(a, b);
	}
}

void	best_move(t_stack **a, t_stack **b)
{
	int	min_and_max[2];
	int	size_a;
	
	longest_sub(a);
	while (check_sub_in_a(a))
	{
		if ((*a)->sub == 0)
		{
			pb(a, b);
			if ((*b)->value < get_median(b, 50))
				rb(b, 1);
		}
		else
			ra(a, 1);
	}
	sort_a_and_b(a, b);
	get_min_and_max(a, min_and_max);
	size_a = ft_lstsize(*a);
	while (get_pos(a, min_and_max[0]) != 0)
	{
		if (get_pos(a, min_and_max[0]) <= (size_a / 2))
			ra(a, 1);
		else
			rra(a, 1);
	}
}
