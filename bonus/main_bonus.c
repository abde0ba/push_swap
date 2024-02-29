/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:34 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/29 18:15:16 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_instructions(char	*str, char **all, t_stack **a)
{
	if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "pa\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "sa\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "sb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "ss\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "ra\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rr\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rra\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
	{
		*all = ft_strjoin(*all, str);
		free(str);
		str = NULL;
	}
	else
	{
		free(str);
		str = NULL;
		free(*all);
		error_handler(a);
	}
}

void	apply_moves(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "pb", ft_strlen("pb")) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "pa", ft_strlen("pa")) == 0)
		pa(a, b);
	else if (ft_strncmp(str, "sa", ft_strlen("sa")) == 0)
		sa(a);
	else if (ft_strncmp(str, "sb", ft_strlen("sb")) == 0)
		sb(b);
	else if (ft_strncmp(str, "ss", ft_strlen("ss")) == 0)
		ss(a, b);
	else if (ft_strncmp(str, "rra", ft_strlen("rra")) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb", ft_strlen("rrb")) == 0)
		rrb(b);
	else if (ft_strncmp(str, "rrr", ft_strlen("rrr")) == 0)
		rrr(a, b);
	else if (ft_strncmp(str, "ra", ft_strlen("ra")) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb", ft_strlen("rb")) == 0)
		rb(b);
	else if (ft_strncmp(str, "rr", ft_strlen("rr")) == 0)
		rr(a, b);
}

static void	check_and_apply(t_stack **a, t_stack **b)
{
	int		i;
	char	*all;
	char	*instruction;
	char	**moves;

	(1) && (all = NULL, instruction = get_next_line(0));
	while (instruction)
		(1) && (check_instructions(instruction, &all, a),
		instruction = get_next_line(0));
	(1) && (moves = ft_split(all, '\n'), free(all), i = 0);
	while (moves && moves[i])
	{
		apply_moves(a, b, moves[i]);
		free(moves[i]);
		i++;
	}
	free(moves);
	moves = NULL;
	if (!check_sorted(*a) && !ft_lstsize(*b))
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	if (*b)
		ft_lstclear(b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	(1) && (a = NULL, b = NULL);
	if (ac >= 2)
	{
		init_stack_a(&a, ac, av);
		check_and_apply(&a, &b);
		ft_lstclear(&a);
	}
	return (0);
}
