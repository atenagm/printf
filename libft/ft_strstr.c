/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:11:02 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/05 05:23:22 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*des;
	char	*src;
	char	*tmpdes;
	char	*tmpsrc;

	des = (char *)big;
	src = (char *)little;
	tmpdes = des;
	tmpsrc = src;
	while (*des && *src)
	{
		if (*des++ == *src)
		{
			if (tmpsrc == src++)
				tmpdes = des - 1;
		}
		else
		{
			des = ++tmpdes;
			src = tmpsrc;
		}
	}
	if (!*src)
		return (tmpdes);
	return (NULL);
}
