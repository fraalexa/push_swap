/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:29:28 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 23:29:28 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_algorithm(t_stack *a, t_stack *b, int x)
{
	int	k;
	int	i;
	int	count;

	count = 0;
	i = 0;
	k = 0;
	while (k < x)
	{
		count = a->len;
		while (i < count)
		{
			if (((a->top->index >> k) & 1) == 0)
				push(b, a, 'b');
			else
				rotate(a, 'a');
			i++;
		}
		i = 0;
		while (b->len > 0)
			push(a, b, 'a');
		k++;
	}
}

void	radixsort(t_stack *a, t_stack *b)
{
	int	x;

	x = 0;
	while (a->len >> x)
		x++;
	radix_algorithm(a, b, x);
}
