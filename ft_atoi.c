/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:32:03 by ngero             #+#    #+#             */
/*   Updated: 2026/09/29 17:34:15 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	total;

	total = 0;
	sign = 1;
	if (*nptr == '-')
		sign = -1 + (*nptr++ - '-');
	if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			break;
		total = total * 10 + (*nptr - '0');
		nptr++;
	}
	return (total * sign);
}
