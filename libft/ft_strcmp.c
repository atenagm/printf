/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:32:01 by vmiron          #+#    #+#             */
/*   Updated: 2017/12/05 06:10:01 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*pnt1;
	unsigned char	*pnt2;

	pnt1 = (unsigned char *)s1;
	pnt2 = (unsigned char *)s2;
	while (*pnt1 && *pnt1 == *pnt2)
	{
		pnt1++;
		pnt2++;
	}
	return (*pnt1 - *pnt2);
}
