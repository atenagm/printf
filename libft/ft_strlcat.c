/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:50:47 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/05 01:14:48 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*pnt;
	size_t	ret;
	size_t	len;

	pnt = (char *)src;
	len = 0;
	while (*dst++)
		len++;
	dst--;
	ret = 0;
	while (*pnt)
	{
		if (len + ++ret < size && size != 0)
			*dst++ = *pnt;
		pnt++;
	}
	*dst = '\0';
	if (len < size)
		size = len;
	return (ret + size);
}
