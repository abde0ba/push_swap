/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:57:06 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/24 15:50:43 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_in_a(t_stack **a, int *right_pos, int num)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (current->next && current->value < num && current->next->value > num)
		{
			*right_pos = current->next->value;
			return ;
		}
		current = current->next;
	}
}

static int	*best_in_a(t_stack **a, int num, int *arr)
{
	int	right_pos;
	int	actions;
	int	size;
	int	min_and_pos[2];

	(1) && (right_pos = -1, actions = 0, size = ft_lstsize(*a),
	min_and_pos[0] = get_median(a, 2));
	if (size && (num > get_median(a, 1) || num < min_and_pos[0]))
		right_pos = min_and_pos[0];
	if ((*a)->value > num && num > ft_lstlast(*a)->value)
		right_pos = (*a)->value;
	else
		loop_in_a(a, &right_pos, num);
	min_and_pos[0] = get_pos(a, right_pos);
	if (min_and_pos[0] <= (size / 2))
		actions += min_and_pos[0];
	else
		actions += size - min_and_pos[0];
	arr[0] = actions;
	arr[1] = right_pos;
	return (arr);
}

static void	calc_best(t_stack **a, t_stack **b, int *num)
{
	t_stack	*tmp;
	int		lowest;
	int		actions;
	int		arr[2];
	int		size;

	(1) && (lowest = ft_lstsize(*a) + ft_lstsize(*b), actions = 0, tmp = *b);
	while (tmp)
	{
		size = ft_lstsize(*b);
		best_in_a(a, tmp->value, arr);
		actions = arr[0];
		if (get_pos(b, tmp->value) <= (size / 2))
			actions += tmp->index;
		else
			actions += size - tmp->index;
		if (actions < lowest)
		{
			lowest = actions;
			num[0] = tmp->value;
			num[1] = arr[1];
		}
		tmp = tmp->next;
	}
}

static void	sort_a_and_b(t_stack **a, t_stack **b)
{
	int		num[2];

	while (*a || *b)
	{
		calc_best(a, b, num);
		if (!*b)
			break ;
		if ((*b)->value != num[0])
		{
			while ((*b)->value != num[0])
			{
				if (get_pos(b, num[0]) <= (ft_lstsize(*b) / 2))
					rb(b, 1);
				else
					rrb(b, 1);
			}
		}
		else if ((*b)->value == num[0] && get_pos(a, num[1]) != 0)
		{
			while (get_pos(a, num[1]) != 0)
			{
			if (get_pos(a, num[1]) <= (ft_lstsize(*a) / 2))
				ra(a, 1);
			else
				rra(a, 1);
			}
		}
		if ((*b)->value == num[0] && get_pos(a, num[1]) == 0)
			pa(a, b);
	}
}

void	best_move(t_stack **a, t_stack **b)
{
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
	while (get_pos(a, get_median(a, 2)) != 0)
	{
		if (get_pos(a, get_median(a, 2)) <= (ft_lstsize(*a) / 2))
			ra(a, 1);
		else
			rra(a, 1);
	}
}
