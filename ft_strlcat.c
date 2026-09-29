/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:24:13 by ngero             #+#    #+#             */
/*   Updated: 2026/09/29 10:43:40 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char				*p_dst;
	size_t				dst_size;
	const char			*p_src;

	p_dst = dst;
	p_src = src;
	while (*p_dst && size)
	{
		size--;
		p_dst++;
	}
	dst_size = p_dst - dst;
	while (*p_src && size > 1)
	{
		*p_dst++ = *p_src++;
		size--;
	}
	while (*p_src)
		p_src++;
	if (size)
		*p_dst = 0;
	return ((dst_size) + (p_src - src));
}
