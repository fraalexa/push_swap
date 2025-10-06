/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:12:02 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 20:12:02 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *a)
{
	int	st;
	int	b;
	int	c;

	st = a->top->n;
	b = a->top->next->n;
	c = a->top->next->next->n;
	if (st > b && b < c && st < c)
		swap_two(a, 'a');
	else if (st > b && b > c)
	{
		swap_two(a, 'a');
		revrotate(a, 'a');
	}
	else if (st > b && b < c && st > c)
		rotate(a, 'a');
	else if (st < b && b > c && st < c)
	{
		swap_two(a, 'a');
		rotate(a, 'a');
	}
	else if (st < b && b > c && st > c)
		revrotate(a, 'a');
}

int	find_min(t_node *temp)
{
	int	pos;
	int	i;
	int	nbr;

	if (!temp)
		return (0);
	nbr = temp->n;
	pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->n < nbr)
		{
			nbr = temp->n;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

void	pos_to_top(t_stack *a, int pos)
{
	if (pos > a->len / 2)
	{
		pos = a->len - pos;
		while (pos--)
			revrotate(a, 'a');
	}
	else
	{
		while (pos--)
			rotate(a, 'a');
	}
}

void	sort4(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_min(a->top);
	pos_to_top(a, pos);
	push(b, a, 'b');
	sort3(a);
	push(a, b, 'a');
}

void	sort5(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_min(a->top);
	pos_to_top(a, pos);
	push(b, a, 'b');
	pos = find_min(a->top);
	pos_to_top(a, pos);
	push(b, a, 'b');
	sort3(a);
	if (b->top->n < b->top->next->n)
		swap_two(b, 'b');
	push(a, b, 'a');
	push(a, b, 'a');
}
