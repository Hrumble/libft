/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:34:49 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 09:38:26 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		lens1;
	size_t		lens2;
	char		*s;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s = malloc((lens1 + lens2 + 1) * sizeof(char));
	ft_memmove(s, s1, lens1);
	ft_memmove(s + lens1, s2, lens2);
	*(s + lens1 + lens2) = 0;
	return (s);
}
