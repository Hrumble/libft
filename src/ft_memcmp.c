/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:53:56 by ngero             #+#    #+#             */
/*   Updated: 2026/09/29 14:56:38 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	if (!n)
		return (0);
	cs1 = s1;
	cs2 = s2;
	while (n > 1)
	{
		if (*cs1 != *cs2)
			break ;
		cs1++;
		cs2++;
		n--;
	}
	return (*(unsigned char *)cs1 - *(unsigned char *)cs2);
}
