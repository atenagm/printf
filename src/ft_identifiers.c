/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:14:40 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 14:50:02 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftprintf.h"

static int	ft_modif_f(t_flag *data, char *str)
{
	if (str[0] == 'h' && str[1] && str[1] == 'h')
	{
		data->modif_f = data->modif_f > 1 ? data->modif_f : 1;
		return (1);
	}
	else if (str[0] == 'h')
		data->modif_f = data->modif_f > 2 ? data->modif_f : 2;
	else if (str[0] == 'l' && str[1] && str[1] == 'l')
	{
		data->modif_f = data->modif_f > 4 ? data->modif_f : 4;
		return (1);
	}
	else if (str[0] == 'l')
		data->modif_f = data->modif_f > 3 ? data->modif_f : 3;
	else if (str[0] == 'j')
		data->modif_f = data->modif_f > 5 ? data->modif_f : 5;
	else if (str[0] == 'z')
		data->modif_f = data->modif_f > 6 ? data->modif_f : 6;
	else
		return (2);
	return (0);
}

static int	ft_width(t_flag *data, char *str, int i)
{
	int tmp;

	if (str[i] == '*')
	{
		tmp = va_arg(data->ptr, int);
		if (tmp < 0)
		{
			data->minus = 1;
			tmp *= -1;
		}
		data->width = tmp;
	}
	else
	{
		data->width = ft_atoi(str + i);
		while (str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
	}
	return (i);
}

static int	ft_prec(t_flag *data, char *str, int i)
{
	int	tmp;

	if (str[i] == '*')
	{
		tmp = va_arg(data->ptr, int);
		if (tmp >= 0)
			data->prec = tmp + 1;
		else
			data->prec = 0;
	}
	else
	{
		data->prec = 1;
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			data->prec += ft_atoi(str + i + 1);
		while (str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
	}
	return (i);
}

static void	ft_flags_sem(t_flag *data, char c)
{
	if (c == '-')
		data->minus = 1;
	else if (c == '+')
		data->plus = 1;
	else if (c == ' ')
		data->pad = 1;
	else if (c == '#')
		data->alt = 1;
}

int			ft_flags(t_flag *data, char *str)
{
	int	i;
	int	r;

	i = 0;
	while (str[i] && (data->spec = ft_specificator(str[i])) == 0)
	{
		r = 0;
		if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#')
			ft_flags_sem(data, str[i]);
		else if (str[i] == '0' && (i == 0 || (str[i - 1] != '.'
			&& (str[i - 1] <= '0' || str[i - 1] > '9'))))
			data->zero = 1;
		else if ((str[i] == '*' && i > 0 && str[i - 1] == '.') || str[i] == '.')
			i = ft_prec(data, str, i);
		else if (str[i] == '*' || (str[i] > '0' && str[i] <= '9'
			&& (i == 0 || (str[i - 1] != '.'))))
			i = ft_width(data, str, i);
		else if ((r = ft_modif_f(data, (str + i))) == 2)
			return (i);
		i += 1 + r;
	}
	return (i);
}
