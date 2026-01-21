/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation-helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:58:59 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/21 11:43:01 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	if (!stack || stack->size == 0)
		return (0);
	max = stack->arr[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	get_max_position(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	if (!stack || stack->size == 0)
		return (0);
	max = stack->arr[0];
	pos = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
		{
			max = stack->arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	shortest_rotation_direction(t_stack *stack, int target_pos)
{
	int	size;
	int	half_size;

	if (!stack || stack->size == 0)
		return (0);
	size = stack->size;
	half_size = size / 2;
	if (target_pos <= half_size)
		return (1);
	else
		return (-1);
}
