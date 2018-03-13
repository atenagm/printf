/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:36:12 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/05 02:20:37 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *pnt;

	pnt = (char *)s;
	while (*pnt)
		if (*pnt++ == (char)c)
			return (--pnt);
	if ((char)c == '\0')
		return (pnt);
	else
		return (NULL);
}
