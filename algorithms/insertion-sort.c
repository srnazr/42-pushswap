/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion-sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:46:09 by nmina             #+#    #+#             */
/*   Updated: 2026/01/25 17:37:43 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_min_to_top(t_stack *a, int pos, int *op_count)
{
	int	size;

	size = a->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, op_count);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(a, op_count);
			pos--;
		}
	}
}

int	find_insert_pos(t_stack *b, int value)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (b->arr[i] < value)
			return (i);
		i++;
	}
	return (b->size);
}

void	rotate_b_to_pos(t_stack *b, int pos, int *op_count)
{
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b, op_count);
	}
	else
	{
		pos = b->size - pos;
		while (pos-- > 0)
			rrb(b, op_count);
	}
}

void	insertion_sort(t_stack *a, t_stack *b, int *op_count)
{
	int	pos;

	while (a->size > 0)
	{
		pos = get_min_position(a);
		rotate_min_to_top(a, pos, op_count);
		pb(a, b, op_count);
	}
	while (b->size > 0)
		pa(a, b, op_count);
}

void	sort_insertion(t_stack **a, t_stack **b, int *op_count)
{
	insertion_sort(*a, *b, op_count);
}
