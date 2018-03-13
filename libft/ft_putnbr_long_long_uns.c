/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_long_uns.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:01:22 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/22 16:47:30 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_long_long_uns(unsigned long long n)
{
	if (n > 9)
	{
		ft_putnbr_long_long_uns(n / 10);
		ft_putnbr_long_long_uns(n % 10);
	}
	else
		ft_putchar(n + 48);
}
