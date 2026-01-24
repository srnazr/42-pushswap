/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:47:05 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/23 11:47:05 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_buckets(t_stack *a, t_stack *b, int bucket_count)
{
	int	bucket_size;
	int limit;
	int	pushed;

	bucket_size = a->size / bucket_count;
	limit = bucket_size;
	pushed = 0;
	if (bucket_size == 0)
		bucket_size = 1;
	while (a->size > 0)
	{
		// this is where sorting using indexes is needed (to compare to the limit)
		if (a->arr[0] < limit)
		{
			pb(a, b);
			pushed++;
			if (bucket_size > 1 && b->arr[0] < limit - (bucket_size / 2))
				rb(b);
		}
		else
			ra(a);
		if (pushed == limit)
			limit += bucket_size;
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	int	pos;
	int	dir;

	while (b->size > 0)
	{
		pos = get_max_position(b);
		dir = shortest_rotation_direction(b, pos);
		if (dir == 1)
			while (pos > 0)
			{
				rb(b);
				pos--;
			}
		else
			while (pos < b->size)
			{
				rrb(b);
				pos++;
			}
		pa(a, b);
	}
}

static int	get_bucket_count(int size)
{
	if (size <= 10)
		return (1);
	if (size <= 100)
		return (5);
	return (11);
}

void	bucket_sort(t_stack *a, t_stack *b)
{
	int	bucket_count;

	if (!a || a->size < 2)
		return ;
	bucket_count = get_bucket_count(a->size);
	push_buckets(a, b, bucket_count);
	push_back(a, b);
}
