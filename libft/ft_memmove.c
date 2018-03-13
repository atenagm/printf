/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:29:22 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/04 23:14:47 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 > str2)
		while (len--)
			str1[len] = str2[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
