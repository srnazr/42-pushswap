/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:06:48 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/06 22:06:48 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PUT IN HEADER FILE LATER
// typedef struct	t_stack
// {
// 	int	*arr;
// 	int	size;
// 	int	capacity;
// }	t_stack;

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->arr)
		free(stack->arr);
	stack->arr = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

void	stack_pop(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 0)
		return ;
	i = 1;
	while (i < stack->size)
	{
		stack->arr[i - 1] = stack->arr[i];
		i++;
	}
	stack->size--;
}

int	check_sort_order(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 1)
		return (1);
	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i - 1] > stack->arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_top(stack t_stack *stack)
{
	if (!stack || stack->size <= 0)
		return (0);
	return (stack->arr[0]);
}
