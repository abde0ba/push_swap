/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:49:45 by abbaraka          #+#    #+#             */
/*   Updated: 2024/02/29 18:15:20 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_sign(char *str, t_stack **a, char **splitted)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
	{
		free_in_splitted(k, splitted);
		error_handler(a);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] != '\0')
	{
		free_in_splitted(k, splitted);
		error_handler(a);
	}
	return (1);
}

int	ft_atoi(char *str, t_stack **a, char **splitted)
{
	int				i;
	unsigned long	number;
	int				sign;

	i = 0;
	number = 0;
	sign = 1;
	check_sign(str, a, splitted);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((sign == 1 && number * 10 + (str[i] - 48) > INT_MAX)
			|| (sign == -1 && number * 10 + (str[i] - 48) > 2147483648))
			error_handler(a);
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	ptr = *lst;
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

t_stack	*ft_lstnew(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->sub = 0;
	return (node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
