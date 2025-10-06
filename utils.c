/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:43:16 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 21:43:16 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap_two(a, 0);
	swap_two(b, 0);
	write(1, "ss\n", 2);
}

void	sort2(t_stack *a)
{
	swap_two(a, 'a');
}

int	findmax(t_stack *b)
{
	t_node	*tmp;
	int		n;

	tmp = b->top;
	n = b->top->n;
	while (tmp)
	{
		if (tmp->n > n)
		{
			n = tmp->n;
		}
		tmp = tmp->next;
	}
	return (n);
}

int	find_max_pos(t_stack *b)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = b->top;
	max = tmp->n;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->n > max)
		{
			max = tmp->n;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	find_chunk_pos(t_stack *a, int flag)
{
	t_node	*tmp;
	int		i;

	tmp = a->top;
	i = 0;
	while (tmp)
	{
		if (tmp->index < flag)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
