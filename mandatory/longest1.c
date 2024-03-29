/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:53:52 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/29 18:15:40 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	mark_sub(t_stack **a, int *subsequence)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (check_if_found(subsequence, current->value))
			current->sub = 1;
		current = current->next;
	}
	free(subsequence);
}

void	longest_increasing_subsequence(t_stack **a, int *arr, int n)
{
	int		*lis;
	int		*parent;
	int		index_end_and_size[3];
	int		*subsequence;

	(1) && (index_end_and_size[0] = 0, index_end_and_size[1] = 0,
	index_end_and_size[2] = n, lis = malloc(n * sizeof(int)),
	parent = malloc(n * sizeof(int)));
	if (!lis || !parent)
		return ;
	while (index_end_and_size[0] < n)
	{
		lis[index_end_and_size[0]] = 1;
		parent[index_end_and_size[0]] = -1;
		index_end_and_size[0]++;
	}
	(1) && (fill_sub(arr, lis, parent, index_end_and_size),
	subsequence = ft_subsequence(arr, parent, index_end_and_size[1]));
	mark_sub(a, subsequence);
	free(lis);
	free(parent);
}

void	longest_sub(t_stack **a)
{
	int	*arr;

	arr = list_to_arr(a);
	longest_increasing_subsequence(a, arr, ft_lstsize(*a));
	free(arr);
}
