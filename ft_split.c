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

char	**ft_split(const char *s, char c)
{
	const char			*word_start;
	char				**word_array;
	int					wa_index;

	word_array = malloc((count_words(s, c) + 1) * sizeof(char *));
	wa_index = 0;
	word_start = 0;
	while (*s)
	{
		while (*s == c)
		{
			word_start = 0;
			s++;
		}
		while (*s != c && *s)
		{
			if (!word_start)
				word_start = s;
			s++;
		}
		if (word_start)
			word_array[wa_index++] = ft_substr(word_start, 0, s - word_start);
	}
	word_array[wa_index] = 0;
	return (word_array);
}
