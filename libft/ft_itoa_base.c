/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:11:44 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 15:18:31 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long nb, int base)
{
	char				*str;
	int					size;
	unsigned long long	tmp;

	tmp = nb;
	size = 1;
	while ((tmp /= base))
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size--] = '\0';
	if (nb == 0)
		str[size] = '0';
	while (nb)
	{
		str[size--] = nb % base + (nb % base > 9 ? 'A' - 10 : '0');
		nb /= base;
	}
	return (str);
}
