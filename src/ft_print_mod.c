/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:27:01 by vmiron           #+#    #+#             */
/*   Updated: 2018/01/23 14:49:02 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

void	ft_print_mod(t_flag *data, char c)
{
	data->width--;
	if (data->width > 0)
		data->printed += data->width;
	data->prec = 0;
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	ft_putchar_i(data->f_width_pad_p, ' ');
	ft_putchar_i(data->f_width_zero, '0');
	if (c)
	{
		ft_putchar(c);
		data->printed++;
	}
	ft_putchar_i(data->f_width_pad_s, ' ');
}
