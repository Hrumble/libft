/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 10:47:12 by ngero             #+#    #+#             */
/*   Updated: 2026/10/01 10:49:57 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*sk;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	sk = *lst;
	while (sk)
	{
		next = sk->next;
		ft_lstdelone(sk, del);
		sk = next;
	}
	*lst = 0;
}
