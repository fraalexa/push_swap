/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:39:30 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 23:39:30 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *a, int pos)
{
	if (pos <= a->len / 2)
		while (pos--)
			rotate(a, 'a');
	else
		while (pos++ < a->len)
			revrotate(a, 'a');
}

static void	stpush(t_stack *a, t_stack *b, int *chunksize)
{
	int	flag;
	int	chunk;
	int	pos;

	flag = 0;
	while (a->len)
	{
		chunk = chunksize[0] + (chunksize[1]-- > 0);
		flag += chunk;
		while (chunk-- && a->len)
		{
			pos = find_chunk_pos(a, flag);
			rotate_to_top(a, pos);
			push(b, a, 'b');
			if (b->top->index < flag - (chunksize[0] / 2))
				rotate(b, 'b');
		}
	}
}

static void	ndpush(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->top)
	{
		pos = find_max_pos(b);
		if (pos <= b->len / 2)
		{
			while (pos--)
				rotate(b, 'b');
		}
		else
		{
			while (pos++ < b->len)
				revrotate(b, 'b');
		}
		push(a, b, 'a');
	}
}

void	chunksort(t_stack *a, t_stack *b)
{
	int	chunksize[2];

	chunksize[0] = 20;
	chunksize[1] = a->len % 20;
	stpush(a, b, chunksize);
	ndpush(a, b);
}
