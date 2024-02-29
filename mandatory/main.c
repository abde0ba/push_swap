/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:49:55 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/29 09:38:25 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack **a, int num)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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

void	init_stack_a(t_stack **a, int ac, char **av)
{
	int		i;
	char	**splitted;
	int		j;
	int		index;

	i = 1;
	index = 0;
	while (i < ac)
	{
		splitted = ft_split(av[i], ' ');
		if (!splitted)
			error_handler(a);
		check_num(splitted, a);
		j = 0;
		while (splitted[j])
		{
			add_to_a(a, ft_atoi(splitted[j], a, splitted), index, splitted);
			j++;
			index++;
		}
		free_splitted_in_init(j, splitted);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	(1) && (a = NULL, b = NULL);
	if (ac >= 2)
	{
		init_stack_a(&a, ac, av);
		if (check_sorted(a))
			sort(&a, &b);
		ft_lstclear(&a);
	}
	return (0);
}
