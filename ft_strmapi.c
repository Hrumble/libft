/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:37:53 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 16:44:03 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*fstr;
	int			i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	fstr = malloc((len + 1) * sizeof(char));
	i = 0;
	while (*s)
	{
		fstr[i] = f(i, *s++);
		i++;
	}
	fstr[i] = 0;
	return (fstr);
}
