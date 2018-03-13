/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:46:06 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:56:05 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

void	ft_data_clean(t_flag *data)
{
	data->minus = 0;
	data->zero = 0;
	data->plus = 0;
	data->pad = 0;
	data->alt = 0;
	data->width = 0;
	data->prec = 0;
	data->len = 0;
	data->spec = 0;
	data->num_len = 0;
	data->is_neg = 0;
	data->modif_f = 0;
	data->f_width_pad_p = 0;
	data->f_semn = 0;
	data->f_width_zero = 0;
	data->f_prec_zero = 0;
	data->f_width_pad_s = 0;
}
