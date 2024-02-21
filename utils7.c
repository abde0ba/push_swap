/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:09:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/21 21:50:43 by abbaraka         ###   ########.fr       */
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
	if (!sorted)
		return (-1);
	(1) && (i = 0, current = *stack);
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
int get_pos(t_stack **stack, int num);

void	sorting_b(t_stack **a, t_stack **b)
{
	int	pivot;
	t_stack	*tmp;
	int		i;

	(void)a;
	tmp = *b;
	i = 0;
	while (i < ft_lstiter(*b))
	{
		pivot = get_median(b, 1);
		tmp = *b;
		if (tmp->value == pivot)
			pa(a, b);
		else if (tmp->next && tmp->value < pivot && tmp->next->value == pivot)
			sb(b);
		else if (get_pos(b, pivot) <= (ft_lstiter(*b) / 2))
			rb(b, 1);
		else
			rrb(b, 1);
		if ((*a)->value > (*a)->next->value)
			sa(a);
		if (!tmp->next)
			break;
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

void	sort_test(t_stack **a, t_stack **b, int pivot)
{
	
	// while (check_sub_in_a(a))
	// {
	// 	if ((*a)->value < pivot)
	// 	{
	// 		if (!check_sub_in_a(a))
	// 			break ;
	// 		else
	// 		{
	// 		pb(a, b);
	// 		if ((*b)->value < get_median(b, 50))
	// 			rb(b, 1);
	// 		if (ft_lstiter(*b) > 2 && (*b)->value > (ft_lstlast(*b))->value)
	// 			rb(b, 1);
	// 		}
	// 	}
	// 	else
	// 		ra(a, 1);
	// }
	
	int	last = ft_lstlast(*a)->value;
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp = *a;
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
	}
	
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
	actions = 0;
	if (num > get_median(a, 1) || num < get_median(a, 2))
			right_pos = get_median(a, 2);
	else
	{
		while (current)
		{
			if (current->next && current->value < num && current->next->value > num)
				right_pos = current->next->value;
			current = current->next;
		}
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

size_t	ft_intlen(int *arr)
{
	size_t	size;
	size = (size_t)sizeof(arr) / (size_t)sizeof(arr[0]);
	return (size);
}

int	*list_to_arr(t_stack **stack)
{
	t_stack	*tmp;
	int		*arr;
	int		i;
	
	arr = malloc(ft_lstiter(*stack) * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	tmp = *stack;
	while (tmp && i < ft_lstiter(*stack))
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

int	*get_sequence(t_stack **a, int *lis, int *arr, int end)
{
	int	*sequence;
	int	clen;
	int	index;
	int	i;

	clen = lis[end];
	index = end;
	sequence = malloc(ft_lstiter(*a) * sizeof(int));
	if (!sequence)
		return (0);
	i = ft_lstiter(*a) - 1;
	while (i >= 0)
	{
		if (lis[i] == clen && arr[i] < arr[index])
		{
			sequence[--clen] = arr[i];
			index = i;
		}
		i--;
	}
	return (sequence);
}

void	allocate_for_2d(int **result, int *sequence, int size)
{
	size++;
	result = malloc(2 * sizeof(int *));
	result[0] = sequence;
	result[1] = malloc(sizeof(int));
	result[1] = &size;
}

int *ft_subsequence(int arr[], int parent[], int endIndex)
{
	int	size;
	int	i;
	int	index;
	int	*sequence;
	int	**result;

	(1) && (index = endIndex, size = 1, result = NULL);
	while (parent[index] != -1)
	{
		index = parent[index];
		size++;
	}
	sequence = malloc((size + 1) * sizeof(int));
	if (!sequence)
		return (NULL);
	(1) && (index = endIndex, i = size);
	while (parent[index] != -1)
	{
		sequence[i] = arr[index];
		index = parent[index];
		i--;	
	}
	sequence[0] = size;
	(parent[index] == -1) && (sequence[1] = arr[index]);
	return (sequence);
}

void fill_sub(int *arr, int lis[], int parent[], int *endIndex, int n)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
				if (lis[i] > lis[*endIndex])
					*endIndex = i;
			}
			j++;
		}
		i++;
	}
}

int	check_if_found(int *arr, int num)
{
	int	i;

	i = 1;
	while (i < arr[0] + 1)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void longestIncreasingSubsequence(t_stack **a, int *arr, int n)
{
    int lis[n];
    int parent[n];
	int	index_and_end[2];
	int	*subsequence;
	t_stack	*current;
	
	index_and_end[1] = 0;
	index_and_end[0] = 0;
	while (index_and_end[0] < n)
	{
		lis[index_and_end[0]] = 1;
        parent[index_and_end[0]] = -1;
		index_and_end[0]++;
	}
	fill_sub(arr, lis, parent, &index_and_end[1], n);
	subsequence = ft_subsequence(arr, parent, index_and_end[1]);
	current = *a;
	while (current)
	{
		if (check_if_found(subsequence, current->value))
			current->sub = 1;
		current = current->next;
	}
}

void	longest_sub(t_stack **a)
{
	int	*arr;
	int	*lis;
	int	i;
	// int	j;

	lis = malloc(ft_lstiter(*a) * sizeof(int));
	if (!lis)
		return ;
	lis[0] = 1;
	i = 1;
	arr = list_to_arr(a);
	size_t	size;
	size = (size_t)sizeof(arr);
	longestIncreasingSubsequence(a, arr, ft_lstiter(*a));
}

void	best_move(t_stack **a, t_stack **b)
{
	// t_stack	*tmp;
	t_stack	*current;
	// int		pivot;
	int		num;

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
	// while (ft_lstiter(*a) > 3)
	// {
	// 	pivot = get_median(a, 0);
	// 	sort_test(a, b, pivot);
	// }
	// sort_3(a);
	

	while (*b)
	{
		num = calc_best(a, b);
		while ((*b)->value != num)
		{
			if (get_pos(b, num) <= (ft_lstiter(*b) / 2))
				rb(b, 1);
			else
				rrb(b, 1);
		}
		current = *a;
		while (current)
		{
			// if ((*a)->value > (*b)->value && ft_lstlast(*a)->value < (*b)->value)
			// 	break ;
			if ((*b)->value > get_median(a, 1) || (*b)->value < get_median(a, 2))
			{
				while (get_pos(a, get_median(a, 2)) != 0)
				{
					if (get_pos(a, get_median(a, 2)) <= (ft_lstiter(*a) / 2))
						ra(a, 1);
					else
						rra(a, 1);
				}
			}
			else if ((*b)->value == num && current->next && current->value < (*b)->value && current->next->value > (*b)->value)
			{
				while (current->next && current->next->value != 0)
				{
					if (current->next->index <= (ft_lstiter(*a) / 2))
						ra(a, 1);
					else
						rra(a, 1);
				}
			}
			current = current->next;
		}	
		pa(a, b);
	}
	
	while (get_pos(a, get_median(a, 2)) != 0)
	{
		if (get_pos(a, get_median(a, 2)) <= (ft_lstiter(*a) / 2))
			ra(a, 1);
		else
			rra(a, 1);
	}
	if (check_sorted(*a))
		printf("not sorted");
	while (*a)
	{
		printf(" %d ->", (*a)->value);
		*a = (*a)->next;
	}
	printf("\nb\n");
	while (*b)
	{
		printf(" %d ->", (*b)->value);
		*b = (*b)->next;
	}
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int	pivot;

	// while (ft_lstiter(*a) > 3)
	// {
	// 	pivot = get_median(a, 50);
	// 	sort_test(a, b, pivot);
	// }
	longest_sub(a);
	while (check_sub_in_a(a))
	{
		if ((*a)->sub == 0)
		{
			pivot = get_median(a, 0);
			if ((*a)->value < pivot)
			{
				pb(a, b);
				if ((*b)->value < get_median(b, 0))
					rb(b, 1);
			}
			else
				ra(a, 1);
		}
		else
			ra(a, 1);
	}
	while (*b)
		sorting_b(a, b);
		while (*a)
	{
		printf(" %d ->", (*a)->value);
		*a = (*a)->next;
	}
	printf("\nb\n");
	while (*b)
	{
		printf(" %d ->", (*b)->value);
		*b = (*b)->next;
	}
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
	else if (ft_lstiter(*a) <= 100)
		best_move(a, b);
	else if (ft_lstiter(*a) <= 500)
		best_move(a, b);
}
