/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:56:32 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 19:23:12 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	ft_putnbr_fd_recurse(int n, int fd)
{
	if (n > 9 || n < -9)
		ft_putnbr_fd_recurse(n / 10, fd);
	ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_fd_recurse(n, fd);
}
