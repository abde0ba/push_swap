/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:02:32 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 15:59:36 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_double(t_stack **a, int num)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->value == num)
			error_handler();
		tmp = tmp->next;
	}
}
