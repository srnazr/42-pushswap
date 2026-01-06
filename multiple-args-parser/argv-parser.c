/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv-parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:41 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/06 17:00:41 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*parse_numbers(char **argv, int argc, int start)
{
	int	i;
	int	n;
	int	*arr;

	if (!argv || start >= argc)
		show_error();
	check_all_args(argv, argc, start);
	n = argc - start;
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
