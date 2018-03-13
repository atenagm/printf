/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:51:51 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static void	ft_func_x(t_flag *data, unsigned long long nb)
{
	if (!(nb == 0 && data->prec == 1))
		data->num_len = ft_long_longlen(nb, 16);
	ft_prec_zero(data);
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_prec_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	if (nb != 0 && data->alt == 1)
	{
		data->spec == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		data->printed += 2;
	}
	ft_putchar_i(data->f_width_zero, '0');
	ft_putchar_i(data->f_prec_zero, '0');
	if (nb == 0 && data->prec != 1)
		ft_putchar('0');
	else if (nb != 0)
		ft_print_itoa_long(nb, 16, data->spec - 23);
	ft_putchar_i(data->f_width_pad_s, ' ');
}

void		ft_func_mod_x(t_flag *data)
{
	if (data->modif_f == 1)
		ft_func_x(data, (unsigned char)va_arg(data->ptr, int));
	else if (data->modif_f == 2)
		ft_func_x(data, (unsigned short)va_arg(data->ptr, int));
	else if (data->modif_f == 3)
		ft_func_x(data, va_arg(data->ptr, unsigned long));
	else if (data->modif_f == 4)
		ft_func_x(data, va_arg(data->ptr, unsigned long long));
	else if (data->modif_f == 5)
		ft_func_x(data, va_arg(data->ptr, intmax_t));
	else if (data->modif_f == 6)
		ft_func_x(data, va_arg(data->ptr, size_t));
	else
		ft_func_x(data, va_arg(data->ptr, unsigned int));
}
