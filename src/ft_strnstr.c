/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:58:04 by ngero             #+#    #+#             */
/*   Updated: 2026/09/29 19:10:30 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char			*lseeker;
	const char			*bseeker;
	size_t				lenseek;

	lseeker = little;
	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		bseeker = big;
		lseeker = little;
		lenseek = len;
		while (*bseeker++ == *lseeker++ && lenseek--)
			if (!*lseeker)
				return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
