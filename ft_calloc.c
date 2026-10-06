/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:35:33 by ngero             #+#    #+#             */
/*   Updated: 2026/09/29 19:10:46 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

int	is_overflow(size_t a, size_t b)
{
	if (b != 0 && b > SIZE_MAX / a)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (is_overflow(nmemb, size))
		return (0);
	s = malloc(nmemb * size);
	if (!s)
		return (0);
	return (ft_memset(s, 0, nmemb * size));
}
