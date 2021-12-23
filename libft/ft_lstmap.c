/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:35:21 by hbui              #+#    #+#             */
/*   Updated: 2021/12/20 20:23:49 by huybui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delitem(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(content);
}	

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;

	new_lst = NULL;
	temp = NULL;
	while (lst && f)
	{
		if (!temp)
		{
			temp = f(lst);
			new_lst = temp;
		}
		else
		{
			temp->next = f(lst);
			temp = temp->next;
			lst = lst->next;
		}
		if (!temp)
		{
			ft_lstdel(&new_lst, delitem);
			return (NULL);
		}
	}
	return (new_lst);
}
