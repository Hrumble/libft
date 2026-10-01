/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngero <ngero@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 10:51:15 by ngero             #+#    #+#             */
/*   Updated: 2026/10/01 11:39:24 by ngero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*next;
	t_list	*new_list;

	new_list = ft_lstnew(f(lst->content));
	next = lst->next;
	ft_lstdelone(lst, del);
	lst = next;
	while (lst)
	{
		ft_lstadd_back(&new_list, ft_lstnew(f(lst->content)));
		next = lst->next;
		ft_lstdelone(lst, del);
		lst = next;
	}
	return (new_list);
}
