/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:32:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/19 12:47:42 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	error_handler(void);
void	check_num(char **str);
int		check_sorted(t_stack *a);
void	ft_lstclear(t_stack **lst);
int		ft_lstiter(t_stack *lst);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
int		check_min(int num, t_stack **stack);
void	find_min_in_3(int min, t_stack **a);
void	find_min_in_4(int min, t_stack **a, t_stack **b);
void	find_min_in_5(int min, t_stack **a, t_stack **b);
void	indexing(t_stack *tmp);

/**** Actions *****/

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int display);
void	rb(t_stack **b, int display);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int display);
void	rrb(t_stack **b, int display);
void	rrr(t_stack **a, t_stack **b);

void	sort(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);

#endif