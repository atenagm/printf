/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:25:44 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/05 20:39:15 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*pnt1;
	char	*pnt2;

	if (s1 != NULL && s2 != NULL)
	{
		pnt1 = (char *)s1;
		pnt2 = (char *)s2;
		while (*pnt1 && *pnt1 == *pnt2)
		{
			pnt1++;
			pnt2++;
		}
		if (*pnt1 == '\0' && *pnt2 == '\0')
			return (1);
	}
	return (0);
}
