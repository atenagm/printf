/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:57:05 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static void	ft_func_c(t_flag *data, unsigned char nb)
{
	data->num_len = 1;
	data->prec = 0;
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_prec_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	ft_putchar_i(data->f_width_zero, '0');
	ft_putchar(nb);
	ft_putchar_i(data->f_width_pad_s, ' ');
}

static void	ft_func_cc(t_flag *data, int nb)
{
	data->num_len = ft_lclen(nb);
	data->prec = 0;
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_prec_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	ft_putchar_i(data->f_width_zero, '0');
	ft_putchar_unicode(nb);
	ft_putchar_i(data->f_width_pad_s, ' ');
}

void		ft_func_mod_c(t_flag *data)
{
	if (data->spec == 'c' && data->modif_f != 3)
		ft_func_c(data, (unsigned char)va_arg(data->ptr, int));
	else
		ft_func_cc(data, va_arg(data->ptr, int));
}
