/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_func_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:46:43 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static void	ft_func_o(t_flag *data, unsigned long long nb)
{
	if (!(nb == 0 && data->prec == 1))
		data->num_len = ft_long_longlen(nb, 8);
	ft_prec_zero(data);
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_prec_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	if (data->alt == 1 && ((nb != 0 && data->num_len >= data->prec - 1)
		|| (nb == 0 && data->prec == 1)))
	{
		ft_putstr("0");
		data->printed += 1;
	}
	ft_putchar_i(data->f_width_zero, '0');
	ft_putchar_i(data->f_prec_zero, '0');
	if (nb == 0 && data->prec != 1)
		ft_putchar('0');
	else if (nb != 0)
		ft_print_itoa_long(nb, 8, 0);
	ft_putchar_i(data->f_width_pad_s, ' ');
}

void		ft_func_mod_o(t_flag *data)
{
	if (data->spec == 'O')
		ft_func_o(data, va_arg(data->ptr, unsigned long long));
	else if (data->modif_f == 1)
		ft_func_o(data, (unsigned char)va_arg(data->ptr, int));
	else if (data->modif_f == 2)
		ft_func_o(data, (unsigned short)va_arg(data->ptr, int));
	else if (data->modif_f == 3)
		ft_func_o(data, va_arg(data->ptr, unsigned long));
	else if (data->modif_f == 4)
		ft_func_o(data, va_arg(data->ptr, unsigned long long));
	else if (data->modif_f == 5)
		ft_func_o(data, va_arg(data->ptr, uintmax_t));
	else if (data->modif_f == 6)
		ft_func_o(data, va_arg(data->ptr, size_t));
	else
		ft_func_o(data, va_arg(data->ptr, unsigned int));
}
