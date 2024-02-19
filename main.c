/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:49:55 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/17 12:30:12 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	add_to_a(t_stack **a, int num, int index)
{
	t_stack	*new;

	check_double(a, num);
	new = ft_lstnew(num);
	new->index = index;
	if (!new)
	{
		free(new);
		new = NULL;
		return ;
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
			free(splitted);
		check_num(splitted);
		j = 0;
		while (splitted[j])
		{
			add_to_a(a, ft_atoi(splitted[j]), index);
			free(splitted[j]);
			j++;
			index++;
		}
		free(splitted);
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
		// while (a)
		// {
		// 	printf("%d : %d\n", a->index, a->value);
		// 	a = a->next;
		// }
	}
	return (0);
}
