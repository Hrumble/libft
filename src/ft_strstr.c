/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <ngero@student.codam.nl>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:00:44 by user              #+#    #+#             */
/*   Updated: 2026/11/15 13:01:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char			*lseeker;
	const char			*bseeker;

	lseeker = little;
	if (!*little)
		return ((char *)big);
	while (*big)
	{
		bseeker = big;
		lseeker = little;
		while (*bseeker++ == *lseeker++)
			if (!*lseeker)
				return ((char *)big);
		big++;
	}
	return (0);
}
