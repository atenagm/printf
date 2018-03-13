/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:16:37 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/04 23:27:06 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*pnt;
	char	*src;

	pnt = s1;
	src = (char *)s2;
	while (*pnt)
		pnt++;
	while (*src)
		*pnt++ = *src++;
	*pnt = '\0';
	return (s1);
}
