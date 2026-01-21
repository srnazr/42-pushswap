/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv-parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:41 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/21 12:36:26 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
- Convert command-line arguments into an int array for the initial stack.
- Start reading from 'start', skipping strategy or flag arguments.
- Validate all arguments with check_all_args() to ensure numeric values.
- Allocate memory for the array and convert each string to int via atoi_arg().
- Check for duplicates with check_duplicates_int(). Call show_error() on failure.
*/
int	*parse_numbers(char **argv, int argc, int start)
{
	int	i;
	int	n;
	int	*arr;

	if (!argv || start >= argc)
		show_error();
	check_all_args(argv, argc, start);
	n = argc - start;
	if (n <= 0)
		show_error();
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		show_error();
	i = 0;
	while (i < n)
	{
		arr[i] = atoi_arg(argv[start + i]);
		i++;
	}
	check_duplicates_int(arr, n);
	return (arr);
}
