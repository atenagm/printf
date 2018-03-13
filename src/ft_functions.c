/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:11:29 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:51:18 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

void	ft_prec_zero(t_flag *data)
{
	if (data->prec > 0)
	{
		if (data->prec - 1 > data->num_len)
			data->f_prec_zero = data->prec - 1 - data->num_len;
	}
}

void	ft_semn(t_flag *data)
{
	if (data->is_neg)
		data->f_semn = '-';
	else if (data->plus)
		data->f_semn = '+';
	else if (data->pad)
		data->f_semn = ' ';
}

void	ft_width_zero(t_flag *data)
{
	int	egl;

	egl = 0;
	if (data->minus == 0 && data->zero == 1 &&
		data->width > 0 && data->prec == 0)
	{
		egl = data->width - data->num_len;
		if (data->f_semn)
			egl--;
		if ((data->alt == 1 && (data->spec == 'x' || data->spec == 'X'))
			|| data->spec == 'p')
			egl -= 2;
		if (data->alt == 1 && (data->spec == 'o' || data->spec == 'O'))
			egl--;
		data->f_width_zero = egl < 0 ? 0 : egl;
	}
}

void	ft_width_pad_p(t_flag *data)
{
	int	egl;

	egl = 0;
	if (data->minus == 0 && data->width > 0 &&
		(data->zero == 0 || data->prec > 0))
	{
		egl = data->width - data->f_prec_zero - data->num_len;
		if (data->f_semn)
			egl--;
		if ((data->alt == 1 && (data->spec == 'x' || data->spec == 'X'))
			|| data->spec == 'p')
			egl -= 2;
		if (data->alt == 1 && (data->spec == 'o' || data->spec == 'O'))
			egl--;
		data->f_width_pad_p = egl < 0 ? 0 : egl;
	}
}

void	ft_width_pad_s(t_flag *data)
{
	int	egl;

	egl = 0;
	if (data->minus == 1 && data->width > 0)
	{
		egl = data->width - data->f_prec_zero - data->num_len;
		if (data->f_semn)
			egl--;
		if ((data->alt == 1 && (data->spec == 'x' || data->spec == 'X'))
			|| data->spec == 'p')
			egl -= 2;
		if (data->alt == 1 && (data->spec == 'o' || data->spec == 'O'))
			egl--;
		data->f_width_pad_s = egl < 0 ? 0 : egl;
	}
}
