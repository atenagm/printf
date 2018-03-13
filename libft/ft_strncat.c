/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:25:29 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/05 00:13:27 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*pnt;
	char	*src;

	pnt = s1;
	src = (char *)s2;
	while (*pnt)
		pnt++;
	while (*src && n--)
		*pnt++ = *src++;
	*pnt = '\0';
	return (s1);
}
