/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:01:46 by ngero             #+#    #+#             */
/*   Updated: 2026/09/30 19:15:22 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	divisible_by_10(int n)
{
	int	tot;

	tot = 1;
	while (!(n < 10 && n > -10))
	{
		tot++;
		n /= 10;
	}
	return (tot);
}

static int	ft_abs(int x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

char	*ft_itoa(int n)
{
	char	*s;
	char	*sk;
	int		len;

	len = (divisible_by_10(n) + 1 + (n < 0));
	s = malloc(len * sizeof(char));
	if (n < 0)
		*s = '-';
	sk = s + len - 1;
	*sk-- = 0;
	while (n > 10 || n < -10)
	{
		*sk-- = ft_abs(n % 10) + '0';
		n /= 10;
	}
	*sk-- = ft_abs(n % 10) + '0';
	return (s);
}
