/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:21:44 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/15 14:22:16 by vmiron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_longlen(unsigned long nb, int base)
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
