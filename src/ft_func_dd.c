/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_dd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:53:56 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:57:42 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

void	ft_func_dd(t_flag *data, long long nb)
{
	if (nb < 0)
		data->is_neg = 1;
	if (!(nb == 0 && data->prec == 1))
		data->num_len = nb == (-9223372036854775807 - 1) ? 19
		: ft_longlen(ft_abs_long(nb), 10);
	ft_prec_zero(data);
	ft_semn(data);
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_prec_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	if (data->f_semn && ++data->printed)
		ft_putchar_i(1, data->f_semn);
	ft_putchar_i(data->f_width_zero, '0');
	ft_putchar_i(data->f_prec_zero, '0');
	if (!(nb == 0 && data->prec == 1))
	{
		nb == (-9223372036854775807 - 1) ? ft_putstr("9223372036854775808")
			: ft_putnbr_long(ft_abs_long(nb));
	}
	ft_putchar_i(data->f_width_pad_s, ' ');
}
