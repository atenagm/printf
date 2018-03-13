/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:50:54 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/01 17:06:34 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strtrim_star(char const *s, size_t i)
{
	size_t	star;

	star = 0;
	while ((s[star] == ' ' || s[star] == '\n' || s[star] == '\t') && star < i)
		star++;
	return (star);
}

static int		ft_strtrim_end(char const *s, size_t i)
{
	size_t	end;

	end = i - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > 0)
		end--;
	return (end);
}

char			*ft_strtrim(char const *s)
{
	char		*pnt;
	char		*ret;
	size_t		i;
	size_t		star;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	star = ft_strtrim_star(s, i);
	i = ft_strtrim_end(s, i) + 1;
	if (i <= star)
		pnt = (char *)malloc(1);
	else
		pnt = (char *)malloc(i - star + 1);
	if (pnt == NULL)
		return (NULL);
	ret = pnt;
	while (star < i)
		*pnt++ = s[star++];
	*pnt = '\0';
	return (ret);
}
