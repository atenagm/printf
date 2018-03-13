/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:53:47 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:47:15 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static void	ft_call_fun(t_flag *data)
{
	if (data->spec == 'd' || data->spec == 'i')
		ft_func_mod_i_d(data);
	else if (data->spec == 'D')
		ft_func_dd(data, va_arg(data->ptr, long));
	else if (data->spec == 'u' || data->spec == 'U')
		ft_func_mod_u(data);
	else if (data->spec == 'x' || data->spec == 'X')
		ft_func_mod_x(data);
	else if (data->spec == 'o' || data->spec == 'O')
		ft_func_mod_o(data);
	else if (data->spec == 'c' || data->spec == 'C')
		ft_func_mod_c(data);
	else if (data->spec == 's' || data->spec == 'S')
		ft_func_mod_s(data);
	else if (data->spec == 'p')
		ft_func_p(data, va_arg(data->ptr, void *));
	else if (data->spec == 'f' || data->spec == 'F')
		ft_func_f(data, va_arg(data->ptr, double));
}

static int	ft_getdata(t_flag *data, char *str)
{
	int	i;

	i = ft_flags(data, str);
	if (data->spec == 0 || data->spec == '%')
		ft_print_mod(data, str[i]);
	else
		ft_call_fun(data);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_flag	data;
	char	*str;

	str = (char *)format;
	va_start(data.ptr, format);
	data.printed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_data_clean(&data);
			str++;
			str += ft_getdata(&data, str);
		}
		else
		{
			ft_putchar(*str);
			data.printed++;
		}
		if (*str)
			str++;
	}
	va_end(data.ptr);
	return (data.printed);
}
