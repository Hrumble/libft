/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <ngero@student.codam.nl>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:25:46 by user              #+#    #+#             */
/*   Updated: 2026/11/09 10:31:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t dsize)
{
   size_t  i;
	
   i = 0;
   while (src[i] && i < dsize)
   {
	   dst[i] = src[i];
	   i++;
   }
   while (i < dsize)
	   dst[i++] = 0;
   return (dst);
}
