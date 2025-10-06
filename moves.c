/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:32:30 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 23:32:30 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_stack *a, char c)
{
	int	temp;

	if (!a || !a->top || !a->top->next)
		return ;
	temp = a->top->n;
	a->top->n = a->top->next->n;
	a->top->next->n = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	push(t_stack *a, t_stack *b, char c)
{
	t_node	*temp;

	if (b->top == NULL)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->next = a->top;
	a->top = temp;
	b->len--;
	a->len++;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack *a, char c)
{
	t_node	*last;
	t_node	*first;

	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	revrotate(t_stack *a, char c)
{
	t_node	*last;
	t_node	*prev;

	if (!a->top || !a->top->next)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	revrotate(a, 0);
	revrotate(b, 0);
	write(1, "rrr\n", 4);
}
