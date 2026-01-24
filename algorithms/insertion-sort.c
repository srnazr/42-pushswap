/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion-sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:46:09 by nmina             #+#    #+#             */
/*   Updated: 2026/01/24 17:56:41 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	In push_swap, algorithms are adapted to stack operations.

	Insertion sort works well for small stacks because elements
	are moved one by one. Stack B is kept sorted, and rotations
	are used instead of shifting memory. This keeps the number
	of operations low and logic simple. Additionally, Stack B is 
    sorted in descending order to optimize the final push back to Stack A.
    (This way, the largest elements are on top of Stack B, ready to be 
    pushed back to Stack A in sorted order.)

	Quick sort requires direct index access and arbitrary
	swaps, which cannot be expressed using stack operations.
	For this reason, quick sort is used only on arrays for
	preprocessing (indexing and chunk calculation), never
	directly on stacks.
*/

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

void	rotate_b_to_pos(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = b->size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 0)
	{
		pos = find_insert_pos(b, get_top(a));
		rotate_b_to_pos(b, pos);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
