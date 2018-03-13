/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:20:24 by vmiron           #+#    #+#             */
/*   Updated: 2018/01/23 15:21:22 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_flag
{
	va_list			ptr;
	int				minus;
	int				zero;
	int				plus;
	int				pad;
	int				alt;
	int				width;
	int				prec;
	int				len;
	char			spec;
	int				num_len;
	int				is_neg;
	int				modif_f;
	int				f_width_pad_p;
	int				f_semn;
	int				f_width_zero;
	int				f_prec_zero;
	int				f_width_pad_s;
	int				printed;
}					t_flag;

int					ft_printf(const char *format, ...);
int					ft_flags(t_flag *data, char *str);
void				ft_data_clean(t_flag *data);
void				ft_func_mod_i_d(t_flag *data);
void				ft_func_dd(t_flag *data, long long nb);
void				ft_putchar_i(int i, char c);
void				ft_prec_zero(t_flag *data);
void				ft_semn(t_flag *data);
void				ft_width_zero(t_flag *data);
void				ft_width_pad_p(t_flag *data);
void				ft_width_pad_s(t_flag *data);
void				ft_func_mod_u(t_flag *data);
void				ft_func_mod_x(t_flag *data);
void				ft_print_itoabase_int(unsigned int nb, int base, char c);
void				ft_print_itoa_long(unsigned long long nb, int base, char c);
void				ft_func_mod_o(t_flag *data);
void				ft_func_mod_c(t_flag *data);
void				ft_func_mod_s(t_flag *data);
void				ft_func_p(t_flag *data, void *nb);
void				ft_func_f(t_flag *data, double nb);
void				ft_prec_zero_f(t_flag *data);
void				ft_width_zero_f(t_flag *data);
void				ft_width_pad_p_f(t_flag *data);
void				ft_width_pad_s_f(t_flag *data);
void				ft_print_mod(t_flag *data, char c);
int					ft_specificator(char c);
#endif
