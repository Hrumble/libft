/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 13:15:42 by ngero             #+#    #+#             */
/*   Updated: 2026/10/10 13:26:23 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_uint_recurse(unsigned int n, int *count)
{
	if (n > 9)
		ft_putnbr_uint_recurse(n / 10, count);
	*count += ft_putchar("0123456789"[n % 10]);
}

int	ft_putnbr_uint(unsigned int n)
{
	int	count;

	count = 0;
	ft_putnbr_uint_recurse(n, &count);
	return (count);
}
