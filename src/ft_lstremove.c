/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <ngero@student.codam.nl>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:00:03 by user              #+#    #+#             */
/*   Updated: 2026/11/09 11:08:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstremove(t_list **lst, int index, void (*del)(void *))
{
	t_list	*sk;
	t_list	*prev;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	prev = 0;
	sk = *lst;
	while (i < index)
	{
		if (!sk)
			return (0);
		prev = sk;
		sk = sk->next;
		i++;
	}
	if (prev)
		prev->next = sk->next;
	else
		*lst = sk->next;
	ft_lstdelone(sk, del);
	return (1);
}
