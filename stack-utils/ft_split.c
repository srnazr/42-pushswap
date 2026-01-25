/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:00:00 by szaarour          #+#    #+#             */
/*   Updated: 2026/01/25 18:05:01 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words_split(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_word_split(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_all_split(char **arr, int words_count)
{
	int	i;

	i = 0;
	while (i < words_count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	fill_words(char **arr, const char *s, char c)
{
	int	i;
	int	start;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[count] = get_word_split(s, start, i);
			if (!arr[count])
				return (-1);
			count++;
		}
	}
	arr[count] = NULL;
	return (0);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		words_count;

	if (!str)
		return (NULL);
	words_count = count_words_split(str, c);
	arr = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (fill_words(arr, str, c) == -1)
	{
		free_all_split(arr, words_count);
		return (NULL);
	}
	return (arr);
}
