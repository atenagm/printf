/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiron <vmiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:26:47 by vmiron          #+#    #+#             */
/*   Updated: 2018/01/23 15:22:32 by vmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "ftprintf.h"

static void    ft_test_f(char *str, double *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_p_ccc(char *str, char **nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, nbr);
	ret2 = printf(str, nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_p_u_l(char *str, unsigned long *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, nbr);
	ret2 = printf(str, nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_p(char *str, int *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, nbr);
	ret2 = printf(str, nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_char(char *str, unsigned char *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_char_s(char *str, char **nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_int_s(char *str, int **nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_int(char *str, int *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_int_x(char *str, unsigned int *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_int_o(char *str, unsigned int *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_int_oo(char *str, unsigned long *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_int_uns(char *str, unsigned int *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_long(char *str, long *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

static void    ft_test_long_uns(char *str, unsigned long *nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, *nbr);
	ret2 = printf(str, *nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}

int	main(void)
{
	char				tychar;
	unsigned char		tyuchar;
	char				*strchar;
	int					*strint;
	short				tyshort;
	unsigned short		tyushort;
	int					tyint;
	unsigned int		tyuint;
	long				tylong;
	unsigned long		tyulong;
	double				tydouble;

	setlocale(LC_ALL, "");
	tychar = 127;
	tyuchar = 255;
	tyshort = 32767;
	tyushort = 65535;
	tyint = 2147483647;
	tyuint = 4294967295;
	tylong = 9223372036854775807U;
	tyulong = 18446744073709551615U;
	tydouble = 2.4441234;

	tyint = 999;
	ft_test_int("test 01 -> {%#7.4d}\n", &tyint);
	tyint = -23;
	ft_test_int("test 01 -> {%7.4d}\n", &tyint);
	tyint = 3;
	ft_test_int("test 02 -> {% 5.2d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 03 -> {% 1d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 04 -> {% 1.2d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 05 -> {% 1.3d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 06 -> {%1.3d}\n", &tyint);
	tyint = -3;
	ft_test_int("test 07 -> {% 5d}\n", &tyint);
	tyint = -3;
	ft_test_int("test 08 -> {% 5.2d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 09 -> {% 1d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 10 -> {% 1.2d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 11 -> {% 1.3d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 12 -> {%1.3d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 13 -> {%4.3d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 14 -> {%5.4d}\n", &tyint);
	tyint = 333;
	ft_test_int("test 15 -> {%+4.3d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 16 -> {%+5.3d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 17 -> {%+5.d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 18 -> {%-+5.d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 19 -> {%-+5.3d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 20 -> {%-+5.3d}\n", &tyint);
	tyint = -33;
	ft_test_int("test 21 -> {%+5.3d}\n", &tyint);
	tyint = 33;
	ft_test_int("test 22 -> {% -5.3d}\n", &tyint);
	tyint = 10000;
	ft_test_int("test 01 -> {%-4d}\n", &tyint);
	tyint = 10000;
	ft_test_int("test 02 -> {%-30d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 03 -> {%10d}\n", &tyint);
	tyint = 10000;
	ft_test_int("test 04 -> {%4d}\n", &tyint);
	tyint = 10000;
	ft_test_int("test 05 -> {%30d}\n", &tyint);
	tyint = -42;
	ft_test_int("test 06 -> {%10d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 07 -> {%010d}\n", &tyint);
	tyint = -42;
	ft_test_int("test 08 -> {%010d}\n", &tyint);
	tyint = 10000;
	ft_test_int("test 09 -> {%04d}\n", &tyint);
	tyint = 10000;
	ft_test_int("test 10 -> {%030d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 11 -> {%+d}\n", &tyint);
	tyint = -42;
	ft_test_int("test 12 -> {%+d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 13 -> {%+i}\n", &tyint);
	tyint = -42;
	ft_test_int("test 14 -> {%+i}\n", &tyint);
	tyint = 9999;
	ft_test_int("test 15 -> {% d}\n", &tyint);
	tyint = -9999;
	ft_test_int("test 16 -> {% d}\n", &tyint);
	tyint = 9999;
	ft_test_int("test 17 -> {% i}\n", &tyint);
	tyint = -9999;
	ft_test_int("test 18 -> {% i}\n", &tyint);
	tyint = 42;
	ft_test_int("test 19 -> {% +d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 20 -> {%+ d}\n", &tyint);
	tyint = 0;
	ft_test_int("test 21 -> {%+03d}\n", &tyint);
	tyint = 0;
	ft_test_int("test 22 -> {% 03d}\n", &tyint);
	tyint = 0;
	ft_test_int("test 23 -> {%0-3d}\n", &tyint);
	tyint = 12;
	ft_test_int("test 24 -> {%+03d}\n", &tyint);
	tyint = 123456;
	ft_test_int("test 25 -> {%+03d}\n", &tyint);
	tyint = 0;
	ft_test_int("test 26 -> {%03.2d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 27 -> {%.4d}\n", &tyint);
	tyint = 424242;
	ft_test_int("test 28 -> {%.4d}\n", &tyint);
	tyint = -424242;
	ft_test_int("test 29 -> {%.4d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 30 -> {%15.4d}\n", &tyint);
	tyint = 424242;
	ft_test_int("test 31 -> {%15.4d}\n", &tyint);
	tyint = 424242424;
	ft_test_int("test 32 -> {%8.4d}\n", &tyint);
	tyint = -42;
	ft_test_int("test 33 -> {%15.4d}\n", &tyint);
	tyint = -424242;
	ft_test_int("test 34 -> {%15.4d}\n", &tyint);
	tyint = -424242424;
	ft_test_int("test 35 -> {%8.4d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 36 -> {%4.15d}\n", &tyint);
	tyint = 424242;
	ft_test_int("test 37 -> {%4.15d}\n", &tyint);
	tyint = 424242424;
	ft_test_int("test 38 -> {%4.8d}\n", &tyint);
	tyint = -42;
	ft_test_int("test 39 -> {%4.15d}\n", &tyint);
	tyint = -424242;
	ft_test_int("test 40 -> {%4.15d}\n", &tyint);
	tyint = -424242424;
	ft_test_int("test 41 -> {%4.8d}\n", &tyint);
	tyint = 0;
	ft_test_int("test 42 -> {%.d}\n", &tyint);
	tyint = 0;
	ft_test_int("test 43 -> {%.0d}\n", &tyint);
	tyint = -42;
	ft_test_int("test 44 -> {%.10d}\n", &tyint);
	tyint = 42;
	ft_test_int("test 45 -> {%.4i}\n", &tyint);
	tyint = 42;
	ft_test_int("test 46 -> {%15.4i}\n", &tyint);
	tyint = -2147483648;
	ft_test_int("test 47 -> {%+4.15i}\n", &tyint);
	tyint = -33;
	ft_test_int("test 47 -> {%.5i}\n", &tyint);
	tyint = 42;
	ft_test_int("test 47 -> {%-0+5d}\n", &tyint);
	tyint = -2147483648;
	ft_test_int("test d -> {%d}\n", &tyint);
	tyint = -2147483648;
	ft_test_int("test i -> {%i}\n", &tyint);
	tyint = 2147483647;
	ft_test_int("test d -> {%d}\n", &tyint);
	tyint = 2147483647;
	ft_test_int("test i -> {%i}\n", &tyint);
	tyint = 4294967295;
	ft_test_int("test d -> {%d}\n", &tyint);
	tyint = 4294967295;
	ft_test_int("test i -> {%i}\n", &tyint);
	tyint = -2147483648;
	ft_test_int("test d -> {%d}\n", &tyint);
	tyint = -2147483648;
	ft_test_int("test i -> {%i}\n", &tyint);
	tyint = -2147483648;
	ft_test_int("test D -> {%D}\n", &tyint);
	tyint = 2147483647;
	ft_test_int("test d -> {%d}\n", &tyint);
	tyint = 2147483647;
	ft_test_int("test i -> {%i}\n", &tyint);
	tyint = 2147483647;
	ft_test_int("test D -> {%D}\n", &tyint);
	tyint = 4294967295;
	ft_test_int("test d -> {%d}\n", &tyint);
	tyint = 4294967295;
	ft_test_int("test i -> {%i}\n", &tyint);
	tyint = 4294967295;
	ft_test_int("test D -> {%D}\n", &tyint);
	tyint = 0L;
	ft_test_int("test D -> {%D}\n", &tyint);
	tyint = 1L;
	ft_test_int("test D -> {%D}\n", &tyint);
	tyint = -1L;
	ft_test_int("test D -> {%D}\n", &tyint);
	tyint = 42L;
	ft_test_int("test D -> {%D}\n", &tyint);
	
	tylong = -9223372036854775808U;
	ft_test_long("test D -> {%D}\n", &tylong);
	tylong = 9223372036854775807U;
	ft_test_long("test D -> {%D}\n", &tylong);
	tylong = 0L;
	ft_test_long("test D -> {%D}\n", &tylong);
	tylong = 1L;
	ft_test_long("test D -> {%D}\n", &tylong);
	tylong = -1L;
	ft_test_long("test D -> {%D}\n", &tylong);
	tylong = 42L;
	ft_test_long("test D -> {%D}\n", &tylong);
	//ft_test("test D -> {%D}\n", -2147483647);
	//ft_test("test -> |% %10      {%-010d}|\n", 123);
	tyint = 234;
	ft_test_int("test D -> {% qqq %}\n", &tyint);

	tyuint = 4294967295;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 0;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 1;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 100;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 999;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 42;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 999988888;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 55555;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);
	tyuint = -100000;
	ft_test_int_uns("test u -> {%u}\n", &tyuint);

	tyulong = 18446744073709551615U;
	ft_test_long_uns("test U -> {%U}\n", &tyulong);
	tyulong = -123;
	ft_test_long_uns("test U -> {%U}\n", &tyulong);
	tyulong = 0;
	ft_test_long_uns("test U -> {%U}\n", &tyulong);
	tyulong = 1844674407370955161U;
	ft_test_long_uns("test U -> {%U}\n", &tyulong);

	tyuint = 1243;
	ft_test_int_x("test x -> {%x}\n", &tyuint);
	tyuint = 0;
	ft_test_int_x("test x -> {%x}\n", &tyuint);
	tyuint = 4294967295;
	ft_test_int_x("test x -> {%x}\n", &tyuint);
	tyuint = 1243;
	ft_test_int_x("test x -> {%#10.1x}\n", &tyuint);
	tyuint = 0;
	ft_test_int_x("test x -> {%#x}\n", &tyuint);
	tyuint = 1243;
	ft_test_int_x("test X -> {%X}\n", &tyuint);
	tyuint = 0;
	ft_test_int_x("test X -> {%Xs}\n", &tyuint);
	tyuint = 4294967295;
	ft_test_int_x("test X -> {%#- .1X}\n", &tyuint);
	tyuint = 234234;
	ft_test_int_x("test X -> {%010#X}\n", &tyuint);
	tyuint = 234234;
	ft_test_int_x("test X -> {%-010#X}\n", &tyuint);
	
	
	tyuint = 42;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 1;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 100;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 999;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 999988888;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 0;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 55555;
	ft_test_int_o("test o -> {%o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%010#o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%10#o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%-10#o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%10.4 30#o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%10.50#o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%010#.o}\n", &tyuint);
	tyuint = 100000;
	ft_test_int_o("test o -> {%#10.50o}\n", &tyuint);
	tyuint = 2;
	ft_test_int_o("test o -> {%#o}\n", &tyuint);
	tyuint = 2;
	ft_test_int_o("test o -> {%010#o}\n", &tyuint);
	tyuint = 2;
	ft_test_int_o("test o -> {%.10#o}\n", &tyuint);
	tyuint = 4294967295;
	ft_test_int_o("test o -> {%.10#o}\n", &tyuint);
	tyuint = 4294967295;
	ft_test_int_o("test o -> {%.10#o}\n", &tyuint);

	tyulong = 2;
	ft_test_int_oo("test o -> {%.10#O}\n", &tyulong);
	tyulong = 18446744073709551615U;
	ft_test_int_oo("test o -> {%.10#O}\n", &tyulong);
	tyulong = 18446744073709551615U;
	ft_test_int_oo("test o -> {%O}\n", &tyulong);
	
	tyuchar = 77;
	ft_test_char("test c -> {%+0 10.3c}\n", &tyuchar);
	tyuchar = 77;
	ft_test_char("test c -> {%+ 10.3c}\n", &tyuchar);
	tyuchar = 77;
	ft_test_char("test c -> {%-0 10.3c}\n", &tyuchar);
	tyuchar = 77;
	ft_test_char("test c -> {%- 10.3c}\n", &tyuchar);
	tyuchar = 77;
	ft_test_char("test c -> {%- 10c}\n", &tyuchar);
	tyuchar = 77;
	ft_test_char("test c -> {%+#10c}\n", &tyuchar);
	tyuchar = 77;
	ft_test_char("test c -> {%- #10c}\n", &tyuchar);
	tyuchar = 0;
	ft_test_char("test c -> {%- #10c}\n", &tyuchar);
	tyuchar = 9;
	ft_test_char("test c -> {%- #10c}\n", &tyuchar);
	tyuchar = 254;
	ft_test_char("test c -> {%- #10c}\n", &tyuchar);
	tyuchar = 255;
	ft_test_char("test c -> {%- #10c}\n", &tyuchar);

	tyint = 1777;
	ft_test_int("test C -> {%C}\n", &tyint);
	tyint = 77;
	ft_test_int("test C -> {%C}\n", &tyint);
	tyint = 1023;
	ft_test_int("test C -> {%C}\n", &tyint);
	// ft_test_int_o("", &tyuint);
	// ft_test_int_x("", &tyuint);
	// ft_test_int_uns("", &tyuint);
	// ft_test_long("", &tylong);
	// ft_test_long_uns("", &tyulong);
	strchar = "string test";
	ft_test_char_s("test s -> {%10.2s}\n", &strchar);
	strchar = "222";
	ft_test_char_s("test s -> {111%s333}\n", &strchar);
	strchar = "222";
	ft_test_char_s("test s -> {%s333}\n", &strchar);
	strchar = "222";
	ft_test_char_s("test s -> {111%s}\n", &strchar);
	strchar = 0;
	ft_test_char_s("test s -> {%s}\n", &strchar);
	strchar = 0;
	ft_test_char_s("test s -> {%10.s}\n", &strchar);
	strchar = 0;
	ft_test_char_s("test s -> {%10.2s}\n", &strchar);
	strchar = 0;
	ft_test_char_s("test s -> {%-10.2s}\n", &strchar);
	strchar = "";
	ft_test_char_s("test s -> {%s}\n", &strchar);
	strchar = "test";
	ft_test_char_s("test s -> {%010s}\n", &strchar);
	strchar = "test";
	ft_test_char_s("test s -> {%-010s}\n", &strchar);
	strchar = "test";
	ft_test_char_s("test s -> {%+ #010s}\n", &strchar);
	strchar = "test";
	ft_test_char_s("test s -> {%+ #010s}\n", &strchar);
	strchar = "test";
	ft_test_char_s("test s -> {%010s}\n", &strchar);

	strint = L"test";
	ft_test_int_s("test S -> {%+ #10S}\n", &strint);
	strint = L"米";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"我是一只猫。";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Α α";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Β β";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Γ γ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Δ δ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ε ε";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Η η";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Θ θ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ι ι";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Κ κ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Λ λ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Μ μ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ν ν";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ξ ξ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ο ο";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Π π";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ρ ρ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Σ σ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Τ τ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Υ υ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Φ φ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Χ χ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ψ ψ";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"Ω ω";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"我";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"猫";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = NULL;
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"我";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"猫";
	ft_test_int_s("test S -> {%S}\n", &strint);
	strint = L"ϪϪ";
	ft_test_int_s("test S -> {%-10.6S}\n", &strint);

	tyint = 10000;
	ft_test_p("test S -> {%0100p}\n", &tyint);
	tyint = 10000;
	ft_test_p("test S -> {%100p}\n", &tyint);
	tyint = 10000;
	ft_test_p("test S -> {%-40.30p}\n", &tyint);
	unsigned long l;
	ft_test_p_u_l("test S -> {%p}\n", &l);
	char *str;
	ft_test_p_ccc("test S -> {%p}\n", &str);
	ft_printf("test S -> {%p}\n", &strlen);
	printf("test S -> {%p}\n", &strlen);

	tydouble = 10.0 / 3.0;
	ft_test_f("01 double {%+.100f}\n", &tydouble);
	
	tydouble = -10.0 / 3.0;
	ft_test_f("02 double {%1.1f}\n", &tydouble);
	tydouble = 1.111;
	ft_test_f("03 double {%20.31f}\n", &tydouble);
	//tydouble = 1.111;
	tydouble = 5.0/3;
	ft_test_f("04 double {%-010f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("05 double {%-0.1f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("06 double {%-010.2f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("07 double {%-010.0f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("08 double {%-010.1f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("09 double {%-010.f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("10 double {%-#010f}\n", &tydouble);
	tydouble = 34634564.123;
	ft_test_f("11 double {%#010.25f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("12 double {%.1 10f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("double {%#1.0f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("double {%#- 00f}\n", &tydouble);
	tydouble = 5.0/3;
	ft_test_f("double {%#- f}\n", &tydouble);
	tydouble = -1444565444646.6465424242242454654;
	ft_test_f("double {%#- f}\n", &tydouble);
	tydouble = 4503599627370496.0;
	ft_test_f("double {%#- f}\n", &tydouble);
	tydouble = 9007199254740992.0;
	ft_test_f("double {%#- f}\n", &tydouble);
	tydouble = 1.111;
	ft_test_f("double {%20f}\n", &tydouble);
	
	tydouble = 19.0 / 10;
	ft_test_f("double {%20.1f}\n", &tydouble);
	tydouble = 19.0 / 10;
	ft_test_f("double {%20.2f}\n", &tydouble);
	tydouble = 19.0 / 10;
	ft_test_f("double {%20.0f}\n", &tydouble);
	tydouble = -1444565444646.6465424242242454654;
	ft_test_f("double {%.100f}\n", &tydouble);
	tydouble = -1444565444646.6465424242242454654;
	ft_test_f("double {%.100F}\n", &tydouble);
	tyuint = -42;
	ft_test_int_o("test o -> {%#o}\n", &tyuint);
	tyuint = 0;
	ft_test_int_o("test o -> {%.o}\n", &tyuint);
	tyuint = 0;
	ft_test_int_o("test o -> {%.O}\n", &tyuint);
	tyuchar = 200;
	ft_test_char("test c -> {%c}\n", &tyuchar);
	tyuint = 0;
	ft_test_int_o("test o -> {%#.o}\n", &tyuint);
	tyuint = 0;
	ft_test_char("test 0 -> {%#.0o}\n", &tyuint);
	tyuint = 0;
	ft_test_int_x("test x -> {%#x}\n", &tyuint);
	return (0);
}
