/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoabase_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:30:30 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:47:56 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

void	ft_print_itoa_long(unsigned long long nb, int base, char c)
{
	if (nb > 0)
	{
		ft_print_itoa_long(nb / base, base, c);
		if (nb % base > 9)
			ft_putchar(nb % base + c - 10);
		else
			ft_putchar(nb % base + '0');
	}
}
