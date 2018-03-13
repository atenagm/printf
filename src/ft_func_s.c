/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 15:24:57 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static void	ft_func_s(t_flag *data, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (ft_strlen(str) > (size_t)(data->prec - 1))
		data->num_len = data->prec - 1;
	else
		data->num_len = ft_strlen(str);
	data->prec = 0;
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	ft_putchar_i(data->f_width_zero, '0');
	while (*str && data->num_len-- > 0)
		ft_putchar(*str++);
	ft_putchar_i(data->f_width_pad_s, ' ');
}

static int	ft_calc_size(t_flag *data, int *str)
{
	int	size;
	int	size_int;

	size = 0;
	while (*str)
	{
		size_int = ft_lclen(*str++);
		if (size + size_int <= data->prec - 1)
			size += size_int;
	}
	return (size);
}

static void	ft_func_ss(t_flag *data, int *str)
{
	if (str == NULL)
		str = L"(null)";
	if (data->prec > 0)
		data->num_len = ft_calc_size(data, str);
	else
		data->num_len = ft_strlenint(str);
	data->prec = 0;
	ft_width_pad_p(data);
	ft_width_zero(data);
	ft_width_pad_s(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_width_pad_s;
	ft_putchar_i(data->f_width_pad_p, ' ');
	ft_putchar_i(data->f_width_zero, '0');
	while (data->num_len > 0)
	{
		data->num_len -= ft_lclen(*str);
		ft_putchar_unicode(*str++);
	}
	ft_putchar_i(data->f_width_pad_s, ' ');
}

void		ft_func_mod_s(t_flag *data)
{
	if (data->spec == 's' && data->modif_f != 3)
		ft_func_s(data, va_arg(data->ptr, char *));
	else
		ft_func_ss(data, va_arg(data->ptr, int *));
}
