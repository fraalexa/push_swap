/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:34:23 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/02 22:34:23 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_alg(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		sort2(a);
	else if (a->len == 3)
		sort3(a);
	else if (a->len == 4)
		sort4(a, b);
	else if (a->len == 5)
		sort5(a, b);
	else if (a->len <= 100)
	{
		indexing(a, bubblesort(cpy_to_arr(a), a->len));
		chunksort(a, b);
	}
	else
	{
		indexing(a, bubblesort(cpy_to_arr(a), a->len));
		radixsort(a, b);
	}
}

void	ft_free(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.len = 0;
	b.top = NULL;
	b.len = 0;
	if (argc < 2)
		return (0);
	parsing(argc - 1, argv + 1, &a);
	if (is_sorted(&a))
	{
		ft_free(&a.top);
		return (0);
	}
	choose_alg(&a, &b);
	ft_free(&a.top);
	ft_free(&b.top);
	return (0);
}
