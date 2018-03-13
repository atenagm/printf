/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:10:53 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 15:18:50 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*pnt;
	int		nb;
	int		sem;
	int		start;

	nb = 0;
	sem = 1;
	pnt = (char *)str;
	start = 0;
	while (*pnt)
	{
		if (*pnt >= '0' && *pnt <= '9' && (start = 1) == 1)
		{
			if ((2147483647 - nb) < (10 + *pnt - 48))
				return ((sem != -1) * -1);
			nb = nb * 10 + *pnt - '0';
		}
		else if (nb == 0 && (*pnt == '-' || *pnt == '+') &&
			(*(pnt + 1) >= '0' && *(pnt + 1) <= '9'))
			sem = ((*pnt == '-') * -1 + (*pnt == '+'));
		else if (start == 1 || (!(*pnt >= 8 && *pnt <= 13) && *pnt != 32))
			return (nb * sem);
		pnt++;
	}
	return (nb * sem);
}
