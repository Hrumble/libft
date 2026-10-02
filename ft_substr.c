/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 08:19:32 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 08:24:50 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		real_len;
	char		*substr;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	real_len = ft_strlen(s + start);
	if (len > real_len)
		len = real_len;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_memcpy(substr, s + start, len);
	*(substr + len) = 0;
	return (substr);
}
