/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:02:08 by ngero             #+#    #+#             */
/*   Updated: 2026/09/29 19:06:23 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char		*sdup;
	size_t		len;

	len = ft_strlen(s);
	sdup = (char *)malloc((len + 1) * sizeof(char));
	if (!sdup)
		return (0);
	ft_memcpy(sdup, s, len * sizeof(char));
	*(sdup + len) = 0;
	return (sdup);
}
