/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:53:45 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

void	ft_func_p(t_flag *data, void *nb)
{
	long	num;

	num = (long)nb;
	if (!(num == 0 && data->prec == 1))
		data->num_len = ft_longlen(num, 16);
	ft_prec_zero(data);
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_prec_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	ft_putstr("0x");
	data->printed += 2;
	ft_putchar_i(data->f_width_zero, '0');
	ft_putchar_i(data->f_prec_zero, '0');
	if (num == 0 && data->prec != 1)
		ft_putchar('0');
	else if (nb != 0)
		ft_print_itoa_long(num, 16, 'a');
	ft_putchar_i(data->f_width_pad_s, ' ');
}
