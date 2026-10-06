/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:54:35 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 15:56:39 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(const char *s, char c)
{
	int	counter;
	int	is_in_word;

	counter = 0;
	is_in_word = 0;
	while (*s)
	{
		while (*s == c)
		{
			is_in_word = 0;
			s++;
		}
		while (*s != c && *s)
		{
			is_in_word = 1;
			s++;
		}
		if (is_in_word)
			counter++;
	}
	return (counter);
}

int	init(char ***word_arr, const char *s, char c, int	*wa_index)
{
	*word_arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!*word_arr)
		return (0);
	*wa_index = 0;
	if (!*word_arr)
		return (0);
	return (1);
}

void	*free_array(char **arr)
{
	char	**w;

	w = arr;
	while (*w)
		free(*w++);
	free(arr);
	return (0);
}

int	assign_word(const char *word_start, size_t len, char **word_array,
		int *wa_index)
{
	if (!word_start)
		return (-1);
	word_array[*wa_index] = ft_substr(word_start, 0, len);
	if (!word_array[*wa_index])
		return (0);
	(*wa_index)++;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	const char			*word_start;
	char				**word_array;
	int					wa_index;

	if (!init(&word_array, s, c, &wa_index))
		return (0);
	word_start = 0;
	while (*s)
	{
		while (*s == c)
			word_start = (const char *)(0 * (size_t)(s++));
		while (*s != c && *s)
		{
			if (!word_start)
				word_start = s;
			s++;
		}
		if (!assign_word(word_start, s - word_start, word_array, &wa_index))
			return (free_array(word_array));
	}
	word_array[wa_index] = 0;
	return (word_array);
}
