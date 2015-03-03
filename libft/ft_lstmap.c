/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 06:19:14 by xacoquan          #+#    #+#             */
/*   Updated: 2015/01/31 06:19:18 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*tmp;
	t_list		*map;

	if (!lst)
		return (0);
	map = (*f)(lst);
	head = ft_lstnew(map->content, map->content_size);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		map = (*f)(lst);
		tmp->next = ft_lstnew(map->content, map->content_size);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
