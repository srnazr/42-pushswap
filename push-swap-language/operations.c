/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:24:35 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/21 11:42:55 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *stack_b)
{
	int	temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->arr[0];
	stack_b->arr[0] = stack_b->arr[1];
	stack_b->arr[1] = temp;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (!stack_a || !stack_b || stack_a->size == 0)
		return ;
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = stack_a->arr[0];
	stack_b->size++;
	stack_pop(stack_a);
}

void	rb(t_stack *stack_b)
{
	int	first;
	int	i;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->arr[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	stack_b->arr[stack_b->size - 1] = first;
}

void	rrb(t_stack *stack_b)
{
	int	last;
	int	i;

	if (!stack_b || stack_b->size < 2)
		return ;
	last = stack_b->arr[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = last;
}

// add rr and rrr later when we merge
