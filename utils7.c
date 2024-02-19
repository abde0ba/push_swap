/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:09:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/19 22:04:02 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value)
		ra(a, 1);
	else if ((*a)->value < (*a)->next->value && (*a)->next->value > (*a)->next->next->value && (*a)->value > (*a)->next->next->value)
		rra(a, 1);
	else if ((*a)->value < (*a)->next->value && (*a)->next->value > (*a)->next->next->value && (*a)->value < (*a)->next->next->value)
	{
		sa(a);
		ra(a, 1);
	}
	else if ((*a)->value > (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
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

void bubbleSort(int *sorted, int n)
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

int	get_median(t_stack **stack, int set)
{
	t_stack	*current;
	int		*sorted;
	int		i;

	sorted = malloc(ft_lstiter(*stack) * sizeof(int));
	i = 0;
	current = *stack;
	while (current)
	{
		sorted[i] = current->value;
		i++;
		current = current->next;
	}
	bubbleSort(sorted, ft_lstiter(*stack));
	if (!set)
		i = sorted[ft_lstiter(*stack) / 4 + 5];
	else if (set == 1)
		i = sorted[ft_lstiter(*stack) - 1];
	else if (set == 2)
		i = sorted[0];
	if (set == 3)
		i = sorted[ft_lstiter(*stack) / 3];
	if (set == 50)
		i = sorted[ft_lstiter(*stack) / 2];
	return (free(sorted), i);
}

int	search_first_50(t_stack *stack)
{
	int i;
	int max;
	int	min;

	i = 0;
	max = get_median(&stack, 1);
	min = get_median(&stack, 2);
	while (stack && i < ft_lstiter(stack) / 2)
	{
		if (stack->value == max || stack->value == min)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	sorting_b(t_stack **a, t_stack **b)
{
	int	pivot;
	t_stack	*tmp;
	int		i;

	tmp = *b;
	i = 0;
	while (i < ft_lstiter(*b))
	{
		pivot = get_median(b, 1);
		tmp = *b;
		if (tmp->value == pivot)
			pa(a, b);
		else if (tmp->value < pivot && tmp->next->value == pivot)
			sb(b);
		else if (!search_first_50(*b))
			rb(b, 1);
		else
			rrb(b, 1);
		if ((*a)->value > (*a)->next->value)
			sa(a);
		i++;
	}
}

int	find_num(t_stack **stack, int num)
{
	t_stack	*tmp;
	
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort_test(t_stack **a, t_stack **b, int pivot)
{
	int	last = ft_lstlast(*a)->value;
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp = *a;
		// if (!find_num(a, pivot))
		// 	break;
		if (temp->value < pivot)
		{
			if (ft_lstiter(*a) == 3)
				break ;
			pb(a, b);
			if ((*b)->value < get_median(b, 50))
				rb(b, 1);
			if (ft_lstiter(*b) > 2 && (*b)->value > (ft_lstlast(*b))->value)
				rb(b, 1);
		}
		else
			ra(a, 1);
		if (temp->value == last)
			break ;	

			
		//working old code !!!! dont delete it;
		
	// 	temp = *a;
	// 	// if (!find_num(a, pivot))
	// 	// 	break;
	// 	if (temp->value < pivot)
	// 	{
	// 		if (ft_lstiter(*a) == 3)
	// 			break ;
	// 		pb(a, b);
	// 		if (ft_lstiter(*b) > 2 && (*b)->value > (ft_lstlast(*b))->value)
	// 			rb(b, 1);
	// 	}
	// 	else
	// 		ra(a, 1);
	// 	if (temp->value == last)
	// 		break ;
	}
}


// void	sort_test2(t_stack **a, t_stack **b, int pivot)
// {
// 	int	last = ft_lstlast(*b)->value;
// 	t_stack	*temp;

// 	temp = *b;
// 	while (temp)
// 	{
// 		temp = *b;
// 		if (temp->value == pivot)
// 			pa(a, b);
// 		// else if (!search_first_50(*b))
// 		// 	rb(b, 1);
// 		else
// 			rrb(b, 1);
// 		if (temp->value == last)
// 			break ;
// 	}
// }

void	quick_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
	int	pivot;

	while (ft_lstiter(*a) > 3)
	{
		pivot = get_median(a, 50);
		sort_test(a, b, pivot);
	}
	sort_3(a);
	while (*b)
		sorting_b(a, b);
	// while ((*a)->value != get_median(a, 2))
	// {
	// 	if (get_median(a, 2) > (ft_lstiter(*a) / 2))
	// 		ra(a, 1);
	// 	else
	// 		rra(a, 1);
	// }
	// sorting_b(a, b);
	// 	sort_test(a, b, pivot);
	// while (ft_lstiter(*a) >= 3)
	// {
	// 	pivot = get_median(a, 0);
	// 	sort_test(a, b, pivot);
	// 	if (ft_lstiter(*a) == 3)
	// 	{
	// 		sort_3(a);
	// 		break ;
	// 	}
	// }
	// while (*b)
	// {
		// pivot = get_median(b, 1);
		// sorting_b(a, b);
	// }
	// if (ft_lstiter(*b) == 2 && (*b)->value < (*b)->next->value)
	// {
	// 	sb(b);
	// 	pa(a, b);
	// 	pa(a, b);
	// }
	// else
	// {
	// 	pa(a, b);	
	// 	pa(a, b);
	// }
	// if (check_sorted(*a))
	// 	quick_sort(a, b);
	// while ((*a))
	// {
	// 	printf("--> %d\t ", (*a)->value);
	// 	(*a) = (*a)->next;
	// }
	// printf("\n");
	// while ((*b))
	// {
	// 	printf("--> %d\t ", (*b)->value);
	// 	(*b) = (*b)->next;
	// }
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

int	best_in_a(t_stack **a, int num)
{
	t_stack	*current;
	int		right_pos;
	int		actions;

	right_pos = -1;
	current = *a;
	while (current)
	{
		if (current->value < num && current->next->value > num)
			right_pos = current->next->value;
		else if (num > get_median(a, 1) || num < get_median(a, 2))
			right_pos = get_median(a, 2);
		current = current->next;
	}
	if (right_pos == -1)
		return (-1);
	if (get_pos(a, right_pos) <= (ft_lstiter(*a) / 2))
		actions += get_pos(a, right_pos);
	else
		actions += ft_lstiter(*a) - get_pos(a, right_pos);
	return (actions);
}

int	calc_best(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		lowest;
	int		actions;
	int		num;

	lowest = ft_lstiter(*a) + ft_lstiter(*b);
	actions = 0;
	tmp = *b;
	while (tmp)
	{
		actions = best_in_a(a, tmp->value);
		if (get_pos(b, tmp->value) <= (ft_lstiter(*b) / 2))
			actions += tmp->index;
		else
			actions += ft_lstiter(*b) - tmp->index;
		if (actions < lowest)
		{
			lowest = actions;
			num = tmp->value;
		}
		tmp = tmp->next;
	}
	return (num);
}

void	best_move(t_stack **a, t_stack **b)
{
	// t_stack	*tmp;
	t_stack	*current;
	int		size;
	int		pivot;
	// int		num;

	size = ft_lstiter(*a);
	while (ft_lstiter(*a) > 3)
	{
		pivot = get_median(a, 0);
		sort_test(a, b, pivot);
	}
	sort_3(a);
	
}

void	selection_sort(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		min;
	int		max;
	int		stop;

	min = get_median(a, 3) * 2;
	max = (get_median(a, 3) * 3);
	stop = ft_lstiter(*a) - (ft_lstiter(*a) / 3);
	tmp = *a;
	while (ft_lstiter(*a) >= stop)
	{
		if ((*a)->value >= min && (*a)->value <= max)
			pb(a, b);
		else
			ra(a, 1);
	}
	// while (*b)
	// {
	// 	if ((*b)->value == get_median(*b))
	// }
	printf ("this is stack a\n");
		while ((*a))
	{
		printf("--> %d\t ", (*a)->value);
		(*a) = (*a)->next;
	}
	printf("\n");
	printf ("this is stack b | min :%d | max : %d\n", min, max);
	while ((*b))
	{
		printf("--> %d\t ", (*b)->value);
		(*b) = (*b)->next;
	}
}





void	sort(t_stack **a, t_stack **b)
{
	if (ft_lstiter(*a) == 2)
		sa(a);
	else if (ft_lstiter(*a) == 3)
		sort_3(a);
	else if (ft_lstiter(*a) == 4)
		sort_4(a, b);
	else if (ft_lstiter(*a) == 5)
		sort_5(a, b);
	else if (ft_lstiter(*a) <= 500)
		best_move(a, b);
}
