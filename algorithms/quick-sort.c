/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:33:53 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/24 17:56:32 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}

int	get_pivot(t_stack *stack, int size)
{
	int	*arr;
	int	i;
	int	pivot;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = stack->arr[i];
		i++;
	}
	quick_sort(arr, 0, size - 1);
	pivot = arr[size / 2];
	free(arr);
	return (pivot);
}

void	sort_quick(t_stack **a, t_stack **b)
{
	int	size;
	int	pivot;
	int	i;

	size = (*a)->size;
	if (size <= 3)
		return (sort_insertion(a, b));
	pivot = get_pivot(*a, size);
	i = 0;
	while (i++ < size)
	{
		if ((*a)->arr[0] < pivot)
			pb(a, b);
		else
			ra(a);
	}
	sort_quick(a, b);
	if ((*b)->size)
		sort_quick(b, a);
	while ((*b)->size)
		pa(a, b);
}
