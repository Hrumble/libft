/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:59:15 by ngero             #+#    #+#             */
/*   Updated: 2026/10/24 02:18:14 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	get_conversion(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789", NULL));
	if (c == 'u')
		return (ft_putnbr_uint(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base_uint(va_arg(ap, int), "0123456789abcdef", NULL));
	if (c == 'X')
		return (ft_putnbr_base_uint(va_arg(ap, int), "0123456789ABCDEF", NULL));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

char	parse_conversion(const char *s, size_t *conversion_size)
{
	*conversion_size = 1;
	if (!*s || *s != '%')
		return (0);
	s++;
	if (*s == 'd' || *s == 's' || *s == 'c'
		|| *s == '%' || *s == 'p' || *s == 'i'
		|| *s == 'x' || *s == 'X' || *s == 'u')
		return (*s);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		character_count;
	char	is_conversion;
	size_t	conversion_size;
	va_list	ap;

	if (!s)
		return (0);
	va_start(ap, s);
	character_count = 0;
	while (*s)
	{
		is_conversion = parse_conversion(s, &conversion_size);
		if (is_conversion)
		{
			character_count += get_conversion(is_conversion, ap);
			s += conversion_size;
		}
		else
		{
			ft_putchar(*s);
			character_count++;
		}
		s++;
	}
	return (character_count);
}

// int main()
// {
// 	// printf("%p", (unsigned long)-1);
// 	ft_printf(NULL);
// 	// printf("%u", -(unsigned)-123);
// }
