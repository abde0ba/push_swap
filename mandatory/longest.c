/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:49:37 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/23 15:23:35 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*ft_subsequence(int arr[], int parent[], int endIndex)
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

void	fill_sub(int *arr, int lis[], int parent[], int index_end_and_size[])
{
	int	i;
	int	j;

	i = 1;
	while (i < index_end_and_size[2])
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
				if (lis[i] > lis[index_end_and_size[1]])
					index_end_and_size[1] = i;
			}
			j++;
		}
		i++;
	}
}
