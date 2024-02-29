/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:16:14 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/28 19:32:06 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	while (tmp)
	{
		if (tmp->next->next == NULL)
			break ;
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	tmp = *b;
	indexing(tmp);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

void	free_splitted_in_init(int j, char **splitted)
{
	while (j)
	{
		free(splitted[j]);
		j--;
	}
	free(splitted[j]);
	free(splitted);
}

void	free_in_splitted(int k, char **splitted)
{
	while (splitted[k])
		k++;
	while (k)
	{
		free(splitted[k]);
		k--;
	}
	free(splitted[k]);
	free(splitted);
}

void	add_to_a(t_stack **a, int num, int index, char **splitted)
{
	t_stack	*new;
	int		k;

	k = 0;
	if (check_double(a, num))
	{
		free_in_splitted(k, splitted);
		error_handler(a);
	}
	new = ft_lstnew(num);
	new->index = index;
	if (!new)
	{
		free(new);
		new = NULL;
		error_handler(a);
	}
	ft_lstadd_back(a, new);
}
