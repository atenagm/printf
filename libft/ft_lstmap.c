/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:22:55 by vmiron          #+#    #+#             */
/*   Updated: 2017/11/30 15:24:40 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*pnt;
	t_list	*tmp;
	t_list	*ret;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	pnt = ft_lstnew(tmp->content, tmp->content_size);
	if (pnt == NULL)
		return (NULL);
	ret = pnt;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		pnt->next = ft_lstnew(tmp->content, tmp->content_size);
		if (pnt == NULL)
			return (NULL);
		pnt = pnt->next;
		lst = lst->next;
	}
	return (ret);
}
