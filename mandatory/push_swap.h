/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:32:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/26 16:04:23 by darkab           ###   ########.fr       */
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
	int				sub;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	error_handler(void);
void	check_num(char **str);
int		check_sorted(t_stack *a);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
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

/**** Initializing & Parsing *****/

void	check_double(t_stack **a, int num);
void	add_to_a(t_stack **a, int num, int index);
void	init_stack_a(t_stack **a, int ac, char **av);

/******* Longest Increasing Subsequence *******/

int		*list_to_arr(t_stack **stack);
int		*ft_subsequence(int arr[], int parent[], int endIndex);
void	fill_sub(int *arr, int lis[], int parent[], int index_end_and_size[]);
int		check_if_found(int *arr, int num);
int		check_sub_in_a(t_stack **a);
void	longest_increasing_subsequence(t_stack **a, int *arr, int n);
void	longest_sub(t_stack **a);

int		get_median(t_stack **stack, int set);
int		*get_min_and_max(t_stack **stack, int *min_and_max);
int		get_pos(t_stack **stack, int num);
void	loop_in_a(t_stack **a, int *right_pos, int	*pos_in_a, int num);
void	best_move(t_stack **a, t_stack **b);

void	bubble_sort(int *sorted, int n);
void	sort(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);

#endif