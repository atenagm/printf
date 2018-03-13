/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:51:09 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:53:39 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

double	ft_modf(double value)
{
	double iptr;
	double absv;

	if ((absv = (value >= 0.0) ? value : -value) >= 4503599627370496)
		iptr = value;
	else
	{
		iptr = absv + 4503599627370496;
		iptr -= 4503599627370496;
		while (iptr > absv)
			iptr -= 1.0;
		if (value < 0.0)
			value *= -1;
	}
	return (value - iptr);
}

void	ft_round(int **array, long *integer, int size)
{
	if ((*array)[size] > 4)
	{
		(*array)[size] = 0;
		if (size == 0)
			(*integer)++;
		else
			(*array)[size - 1] += 1;
		if (size >= 0 && (*array)[size - 1] > 9)
			ft_round(array, integer, size - 1);
	}
}

int		*ft_decimal_ar(double nb, long *integer, int size)
{
	int			*array;
	double		decimal;
	long long	dclong;
	int			i;

	array = (int *)malloc(sizeof(int) * 18);
	decimal = ft_modf(nb);
	dclong = (long long)(decimal * 1000000000000000000);
	*integer = ft_abs_long((long)nb);
	i = 17;
	while (dclong > 0)
	{
		array[i] = (int)(dclong % 10);
		dclong /= 10;
		i--;
	}
	ft_round(&array, integer, size);
	return (array);
}

void	ft_func_f(t_flag *data, double nb)
{
	int		*decimal;
	long	integer;

	ft_prec_zero_f(data);
	decimal = ft_decimal_ar(nb, &integer, data->f_prec_zero);
	data->is_neg = nb < 0 ? 1 : 0;
	data->num_len = ft_longlen(integer, 10);
	ft_semn(data);
	ft_width_pad_p_f(data);
	ft_width_zero_f(data);
	ft_width_pad_s_f(data);
	data->printed += data->num_len + data->f_width_pad_p +
		data->f_width_zero + data->f_width_pad_s + data->f_prec_zero;
	ft_putchar_i(data->f_width_pad_p, ' ');
	if (data->f_semn && ++data->printed)
		ft_putchar_i(1, data->f_semn);
	ft_putchar_i(data->f_width_zero, '0');
	ft_putnbr_long(integer);
	if ((data->f_prec_zero > 0 || data->alt) && ++data->printed)
		ft_putchar('.');
	data->num_len = -1;
	while (++data->num_len < data->f_prec_zero)
		ft_putchar('0' + (data->num_len > 17 ? 0 : decimal[data->num_len]));
	free(decimal);
	ft_putchar_i(data->f_width_pad_s, ' ');
}
