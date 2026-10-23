/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:55:08 by ngero             #+#    #+#             */
/*   Updated: 2026/10/10 14:03:31 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_recurse(unsigned int n, char *base,
		unsigned int base_len, int *count)
{
	if (n >= base_len)
		ft_putnbr_base_recurse(n / base_len, base, base_len, count);
	*count += ft_putchar(base[n % base_len]);
}

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_putnbr_base(int n, char *base, char *prefix)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (prefix)
		count += ft_putstr(prefix);
	if (n < 0)
	{
		count += ft_putchar('-');
		ft_putnbr_base_recurse(0u - n, base, base_len, &count);
	}
	else
		ft_putnbr_base_recurse(n, base, base_len, &count);
	return (count);
}

int	ft_putnbr_base_uint(unsigned int n, char *base, char *prefix)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (prefix)
		count += ft_putstr(prefix);
	ft_putnbr_base_recurse(n, base, base_len, &count);
	return (count);
}
