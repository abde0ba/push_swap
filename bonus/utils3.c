/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:55:10 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/25 15:57:43 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


void	error_handler(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	check_num(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str[0])
		error_handler();
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '+' && str[i][j] != '-' && !(str[i]))
				error_handler();
			j++;
		}
		i++;
	}
}

int	check_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;

	if (lst)
	{
		while (*lst)
		{
			ptr = *lst;
			*lst = (*lst)->next;
			free(ptr);
			ptr = NULL;
		}
		*lst = NULL;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
