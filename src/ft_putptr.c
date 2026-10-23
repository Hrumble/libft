/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:45:19 by ngero             #+#    #+#             */
/*   Updated: 2026/10/10 13:31:26 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	ft_putptr_recurse(uintptr_t n, int *count)
{
	if (n >= 16)
		ft_putptr_recurse(n / 16, count);
	*count += ft_putchar("0123456789abcdef"[n % 16]);
}

int	ft_putptr(void *p)
{
	int	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	ft_putptr_recurse((uintptr_t)p, &count);
	return (count);
}
