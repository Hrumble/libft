/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:24:03 by ngero             #+#    #+#             */
/*   Updated: 2026/10/29 22:25:59 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_alloc;

	if (!ptr)
		new_alloc = malloc(size);
	else
	{
		new_alloc = malloc(size * 2);
		if (!new_alloc)
			return (0);
		ft_memcpy(new_alloc, ptr, size);
		free(ptr);
	}
	return (new_alloc);
}
