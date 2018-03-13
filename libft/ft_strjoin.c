/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:30:13 by vmiron          #+#    #+#             */
/*   Updated: 2017/11/30 01:48:24 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnt;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	pnt = (char *)malloc(i + j + 1);
	if (pnt == NULL)
		return (NULL);
	j += i;
	pnt[j] = '\0';
	while (j-- > 0)
	{
		if (j < i)
			pnt[j] = s1[j];
		else
			pnt[j] = s2[j - i];
	}
	return (pnt);
}
