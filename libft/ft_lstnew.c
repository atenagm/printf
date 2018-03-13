/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:44:16 by vmiron          #+#    #+#             */
/*   Updated: 2017/11/30 01:50:04 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*pnt;

	pnt = (t_list *)malloc(sizeof(t_list));
	if (pnt == NULL)
		return (NULL);
	if (content == NULL)
	{
		pnt->content = NULL;
		pnt->content_size = 0;
	}
	else
	{
		pnt->content = malloc(content_size);
		if (pnt->content == NULL)
			return (NULL);
		ft_memcpy(pnt->content, content, content_size);
		pnt->content_size = content_size;
	}
	pnt->next = NULL;
	return (pnt);
}
