/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:45:12 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 22:45:12 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	if (!a || !a->top)
		return (1);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_inputs(int argc,	char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			ft_error();
		i++;
	}
}

int	check_dup(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = a->top;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp1->n == tmp->n)
				ft_error();
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
