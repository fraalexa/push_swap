/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:06:07 by fraalexa          #+#    #+#             */
/*   Updated: 2025/10/05 20:06:07 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cpy_to_arr(t_stack *a)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = malloc(4 * a->len);
	if (!arr)
		return (NULL);
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

int	*bubblesort(int *arr, int len)
{
	int	temp;
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		i = 0;
	}
	return (arr);
}

void	indexing(t_stack *a, int *arr)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->top;
	while (i < a->len)
	{
		while (temp)
		{
			if (temp->n == arr[i])
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		temp = a->top;
		i++;
	}
}
