/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_longlen_uns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:21:44 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/22 16:46:26 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_long_longlen(unsigned long long nb, int base)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		i++;
		nb /= base;
	}
	return (i);
}
