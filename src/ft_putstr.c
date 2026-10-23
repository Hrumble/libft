/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:54:28 by ngero             #+#    #+#             */
/*   Updated: 2026/10/10 13:31:51 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}
