/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkab <darkab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:32:25 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/28 19:53:32 by darkab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				sub;
	struct s_stack	*next;
}	t_stack;

/**** Get_Next_Line *****/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s);
char	*ft_strdup(char *s1);

/**** Utils Of Push Swap *****/

char	**ft_split(char const *s, char c);
int		ft_atoi(char *str, t_stack **a, char **splitted);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	error_handler(t_stack **a);
void	check_num(char **str, t_stack **a);
int		check_sorted(t_stack *a);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
int		check_min(int num, t_stack **stack);
void	indexing(t_stack *tmp);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**** Actions *****/

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/**** Initializing & Parsing *****/

void	free_in_splitted(int k, char **splitted);
void	free_splitted_in_init(int j, char **splitted);
int		check_double(t_stack **a, int num);
void	add_to_a(t_stack **a, int num, int index, char **splitted);
void	init_stack_a(t_stack **a, int ac, char **av);

#endif