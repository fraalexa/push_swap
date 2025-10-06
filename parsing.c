/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:40:22 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 22:40:22 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(char **arr, int sign)
{
	long long	res;
	t_node		*newnode;

	res = 0;
	while (**arr >= '0' && **arr <= '9')
	{
		res = res * 10 + (**arr - '0');
		(*arr)++;
	}
	if (sign)
		res = -res;
	if (**arr == '+' || **arr == '-')
		ft_error();
	if (res > INT_MAX || res < INT_MIN)
		ft_error();
	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->n = (int)res;
	newnode->next = NULL;
	return (newnode);
}

static void	fillstack(char **arr, t_stack *a, int sign)
{
	t_node	*newnode;
	t_node	*tmp;

	newnode = create_node(arr, sign);
	if (!newnode)
		return ;
	if (!a->top)
		a->top = newnode;
	else
	{
		tmp = a->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newnode;
	}
}

static int	skip(char **arr)
{
	int	sign;

	sign = 0;
	while (**arr == ' ')
		(*arr)++;
	if (**arr == '\0')
		return (0);
	if (**arr == '-' || **arr == '+')
	{
		if (**arr == '-')
			sign = 1;
		(*arr)++;
		if (**arr < '0' || **arr > '9')
			ft_error();
	}
	if (**arr < '0' || **arr > '9')
		ft_error();
	return (sign);
}

void	parsing(int argc, char **argv, t_stack *a)
{
	int		sign;
	int		elems;
	int		i;
	char	*str;

	i = 0;
	elems = 0;
	while (i < argc)
	{
		if (!(*argv[i]))
			ft_error();
		str = argv[i];
		while (*str)
		{
			sign = skip(&str);
			fillstack(&str, a, sign);
			elems++;
			while (*str == ' ')
				str++;
		}
		i++;
	}
	a->len = elems;
	check_dup(a);
}
