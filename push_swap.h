/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalexa <fraalexa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:46:41 by fraalexa          #+#    #+#             */
/*   Updated: 2025/05/30 17:46:41 by fraalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct node
{
	int			n;
	struct node	*next;
	int			index;
}	t_node;

typedef struct stack
{
	t_node	*top;
	int		len;
}	t_stack;

int		find_chunk_pos(t_stack *a, int flag);
int		find_max_pos(t_stack *b);
int		findmax(t_stack *b);
int		is_number(char *str);
int		is_sorted(t_stack *a);
void	parsing(int argc, char **argv, t_stack *a);
void	pos_to_top(t_stack *a, int pos);
int		find_min(t_node *temp);
int		check_dup(t_stack *a);
int		sort(t_stack a, t_stack b);
void	swap_two(t_stack *a, char c);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *a, t_stack *b, char c);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	rotate(t_stack *a, char c);
void	revrotate(t_stack *a, char c);
int		rr(t_stack a, t_stack b);
void	sort2(t_stack *a);
void	sort3(t_stack *a);
void	sort4(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);
int		*cpy_to_arr(t_stack *a);
void	ft_error(void);
void	check_inputs(int argc,	char **argv);
void	ft_free(t_node **lst);
int		*bubblesort(int *arr, int len);
void	indexing(t_stack *a, int *arr);
void	radixsort(t_stack *a, t_stack *b);
void	chunksort(t_stack *a, t_stack *b);

#endif