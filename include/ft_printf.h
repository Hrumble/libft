/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:01:38 by ngero             #+#    #+#             */
/*   Updated: 2026/10/10 13:44:07 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int	ft_printf(const char *s, ...);
// put base
int	ft_putstr(char *s);
int	ft_putchar(int n);
// put number
int	ft_putnbr_uint(unsigned int n);
int	ft_putnbr_base(int n, char *base, char *prefix);
int	ft_putnbr_base_uint(unsigned int n, char *base, char *prefix);
int	ft_putptr(void *p);
#endif
