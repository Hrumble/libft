/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:31:42 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 10:44:22 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	char				*s;
	size_t			len;

	len = ft_strlen(s1);
	start = s1;
	end = s1 + len;
	while (is_in_set(*start, set))
		start++;
	while (is_in_set(*(end - 1), set))
		end--;
	s = malloc((end - start + 1) * sizeof(char));
	ft_memcpy(s, start, end - start);
	*(s + (end - start)) = 0;
	return (s);
}

