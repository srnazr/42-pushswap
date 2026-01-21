/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:04:55 by nmina             #+#    #+#             */
/*   Updated: 2026/01/21 18:05:19 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
