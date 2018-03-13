/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:26:01 by vmiron          #+#    #+#             */
/*   Updated: 2017/11/30 15:51:42 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*pnt;
	int		j;
	size_t	i;

	pnt = (char *)malloc(len + 1);
	if (s == NULL)
		return (0);
	if (pnt == NULL)
		return (NULL);
	j = 0;
	i = (size_t)start;
	len += i;
	while (i < len)
		pnt[j++] = s[i++];
	pnt[j] = '\0';
	return (pnt);
}
