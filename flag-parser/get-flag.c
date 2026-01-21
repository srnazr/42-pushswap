/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:34:04 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/21 11:42:07 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_allowed_flag(char *s)
{
	if (!s)
		return (0);
	// nour flags here
	else if (ft_strcmp(s, "--complex") == 0)
		return (1);
	else if (ft_strcmp(s, "--adaptive") == 0)
		return (1);
	return (0);
}

// returns index of first number - check maa nour if we are allowing 1 selector only???
int	get_start(char **argv, int argc)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (i < argc && is_allowed_flag(argv[i]))
	{
		c++;
		i++;
	}
	if (c > 1)
		show_error();
	return (i);
}
