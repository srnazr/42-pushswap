/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:03:40 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/21 11:42:44 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	show_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	atoi_arg(char *str)
{
	long	nb;
	int		i;
	int		sign;

	if (!str || str[0] == '\0')
		show_error();
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		show_error();
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		show_error();
	return ((int)(nb * sign));
}

// check returned number with int max/min (nour func)
