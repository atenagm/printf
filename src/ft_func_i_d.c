/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:52:19 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static void	ft_func_i_d(t_flag *data, int nb)
{
	if (nb < 0)
		data->is_neg = 1;
	if (!(nb == 0 && data->prec == 1))
		data->num_len = nb == -2147483648 ? 10 : ft_intlen(ft_abs(nb), 10);
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
		nb == -2147483648 ? ft_putstr("2147483648") : ft_putnbr(ft_abs(nb));
	}
	ft_putchar_i(data->f_width_pad_s, ' ');
}

void		ft_func_mod_i_d(t_flag *data)
{
	if (data->modif_f == 1)
		ft_func_i_d(data, (char)va_arg(data->ptr, int));
	else if (data->modif_f == 2)
		ft_func_i_d(data, (short)va_arg(data->ptr, int));
	else if (data->modif_f == 3)
		ft_func_dd(data, va_arg(data->ptr, long));
	else if (data->modif_f == 4)
		ft_func_dd(data, va_arg(data->ptr, long long));
	else if (data->modif_f == 5)
		ft_func_dd(data, va_arg(data->ptr, intmax_t));
	else if (data->modif_f == 6)
		ft_func_dd(data, va_arg(data->ptr, size_t));
	else
		ft_func_i_d(data, va_arg(data->ptr, int));
}
