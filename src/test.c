/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:34:06 by smaccary          #+#    #+#             */
/*   Updated: 2020/05/30 02:43:59 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../libftprintf.h"
#include <limits.h>
#include <string.h>

#define T_PRINTF(f_, ...) {\
	int nb1;\
	int nb2;\
	printf("\033[1;35m\n###############\t\tFORMAT : (%s)\t\t###############\n\033[1;32mprintf:\t\t|", f_);\
	fflush(stdout);\
	nb1 = printf(f_, __VA_ARGS__);\
	fflush(stdout);\
	write(1, "|", 1);\
	fflush(stdout);\
	printf("\033[1;36m\nft_printf:\t|");\
	fflush(stdout);\
	nb2 = ft_printf(f_, __VA_ARGS__);\
	printf("|\n");\
	printf("\033[1;35m\n###############\t\tRETURN VALUES\t\t###############\n\033[1;32mprintf:\t\t|%d|\n\033[1;36mft_printf:\t|%d|\n", nb1, nb2);\
	if (nb1 != nb2)	printf("\n\033[31m		/!\\ THE RETURN VALUES DIFFER /!\\\033[0m\n");\
	printf("\n\033[1;34m***************************************************************\n\033[0m");\
	fflush(stdout);\
}

#define T_NO_ARG_PRINTF(f_) {\
	int nb1;\
	int nb2;\
	printf("\033[1;35m\n###############\t\tFORMAT : (%s)\t\t###############\n\033[1;32mprintf:\t\t|", f_);\
	fflush(stdout);\
	nb1 = printf(f_);\
	fflush(stdout);\
	write(1, "|", 1);\
	fflush(stdout);\
	printf("\033[1;36m\nft_printf:\t|");\
	fflush(stdout);\
	nb2 = ft_printf(f_);\
	printf("|\n");\
	printf("\033[1;35m\n###############\t\tRETURN VALUES\t\t###############\n\033[1;32mprintf:\t\t|%d|\n\033[1;36mft_printf:\t|%d|\n\n\033[1;34m***************************************************************\n\033[0m", nb1, nb2);\
	fflush(stdout);\
}

void tst_printf(char *f, ...)
{}

void	test1(void)
{
	char	*ptr = malloc(1);
	char 	str[]= "\nyeeet |%%| |%c| |%d| |%p| |%X| |%s| \\|%s|\\ \
Je suis actuellement en train de manger du pain--d- \
|%6d| |%-03d|_|%%| |%00*d| |%15.10d| |%-15.10d| |%15.1d|\n";

	ft_printf("\nft_printf (%d)\n", ft_printf(str, 'P', 3, ptr, 756,
			   	"JE SUIS UNE PETITE SOURIS", NULL, 500,
			   	9, 10, 7777, 123456789, -123456789, 123456789));

	printf("\nprintf (%d) \n", printf(str, 'P', 3, ptr, 756,
			   	"JE SUIS UNE PETITE SOURIS", NULL, 500,
			   	9, 10, 7777, 123456789, -123456789, 123456789));
	free(ptr);
}

void	test2(void)
{
	int nb1;
	int nb2;

	write(1, "ft_printf:\t", 11);
	nb1 = ft_printf("|%0*d|\n", 10, 7777);
	write(1, "printf:\t\t", 9);
	nb2 = printf("|%0*d|\n", 10, 7777);
	printf("ft_printf: %d | printf: %d\n", nb1, nb2);
}

void	test3(void)
{
	ft_printf("|% d|\n", 0x9999);
	printf("|% d|\n", 0x9999);
}

/*	undefined
void test4(void)
{
	//undefined
	ft_printf("|%-0", 42);
	printf("|%-0", 42);
	//#if 1
	// #warning "helps"
	//	#endif
}
*/

void test5(void)
{
	int		nb1;
	int		nb2;
	char 	str[]= "\nyeeet |%%| |%c| |%d| |%p| |%X| |%s| \\|%s|\\ Je suis actuellement en train de manger du pain--d- |%6d| |%-03d|_|%%| |%00*d|\n";
	char	*ptr = malloc(1);

	nb1 = printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	fflush(stdout);
	nb2 = ft_printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	printf("%d|%d\n", nb1, nb2);	

	ft_printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	//printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	free(ptr);
}

void test6(void)
{
	int		nb1;
	int		nb2;

	nb1 = printf("Bonjour\n");
	nb2 = ft_printf("Bonjour\n");
	printf("%d|%d\n", nb1, nb2);
}

void test7(void)
{
	int		nb1;
	int		nb2;
	char	str[]= "|%15.10d|\n";

	nb1 = printf(str, -1234567);
	nb2 = ft_printf(str, -1234567);
	printf("%d|%d\n", nb1, nb2);
}

void test8(void)
{
	//minimal field width + precision with ints
	int		nb1;
	int		nb2;
	char	str[]= "|%-15.10d|\n";

	nb1 = printf(str, -1234567);
	nb2 = ft_printf(str, -1234567);
	printf("%d|%d\n", nb1, nb2);
}

void test9(void)
{
	//ONLY PRECISION WITH NUMBERS
	int		nb1;
	int		nb2;
	char	str[]= "|%.20p| |%.20x| |%.20X|\n";

	nb1 = printf(str, (char *)-50, -50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}

void test10(void)
{
	//undefined
	int		nb1;
	int		nb2;
	char	str[]= "|%-1-5.10p|  |%-1-5.10X|\n";

	nb1 = printf(str, (char *)-50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}

void test11(void)
{
	//undefined
	int		nb1;
	int		nb2;
	char	str[]= "|%1-5.10p| |%1-5.10X|\n";

	nb1 = printf(str, (char *)-50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}

void test12(void)
{
	//	undefined ?
	int		nb1;
	int		nb2;
	char	str[]= "|%15-1d|\n";
	nb1 = printf(str, 123456789);
	nb2 = ft_printf(str, 123456789);
	printf("%d|%d\n", nb1, nb2);
}

void test13(void)
{
	int		nb1 = 0;
	int		nb2 = 0;
	//undefined (SEGFAULT)
	//nb1 = printf(NULL);
	nb2 = ft_printf(NULL);
	printf("%d|%d\n", nb1, nb2);
}

void test14(void)
{
	//minimal field width + precision with ints POSITIVE
	int		nb1;
	int		nb2;
	char	str[]= "|%15.10d|\n";

	nb1 = printf(str, 1234567);
	nb2 = ft_printf(str, 1234567);
	printf("%d|%d\n", nb1, nb2);
}

void test15(void)
{
	//minimal field width + precision with chars
	int		nb1;
	int		nb2;
	char	str[]= "|%015.10c| |%015c|\n";

	nb1 = printf(str, 'O', 'O');
	nb2 = ft_printf(str, 'O', 'O');
	printf("%d|%d\n", nb1, nb2);
}

void test16(void)
{
	//minimal field width + LOW precision with ints POSITIVE
	int		nb1;
	int		nb2;
	char	str[]= "|%15.2X|\n";

	nb1 = printf(str, 1234567);
	nb2 = ft_printf(str, 1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test17(void)
{
	//minimal field width + LOW precision with unsigned hex int + int
	int		nb1;
	int		nb2;
	char	str[]= "|%15.1p|\t|%15.11d|\n";

	nb1 = printf(str, 1234567, 1234567);
	nb2 = ft_printf(str, 1234567, 1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test18(void)
{
	// 0 padding + * flag + negative int
	int		nb1;
	int		nb2;
	char	str[]= "|%0*d|\n";
	
	write(1, "printf:\t\t", 9);
	nb1 = printf(str, 20, -1234567);
	write(1, "ft_printf:\t", 11);
	nb2 = ft_printf(str, 20, -1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test19(void)
{
	// POINTER PADDING
	int		nb1;
	int		nb2;
	int		nb_in = -1234567;
	int		width = 20;
	char	str[]= "(%0*p)\t(%*p)\t(%-0*p)\t(%-*p)\n";
	
	write(1, "printf:\t\t", 9);
	nb1 = printf(str, width, nb_in, width, nb_in, width, nb_in, width, nb_in);
	write(1, "ft_printf:\t", 11);
	nb2 = ft_printf(str, width, nb_in, width, nb_in, width, nb_in, width, nb_in);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void hello_world(void)
{
	T_NO_ARG_PRINTF("|HelloT_PRINTF World!|");
}

void	solo_int(int nb)
{
	T_PRINTF("|%d|", nb);
}

void	mazoise_2(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	ft_printf(" --- Return : %d\n", ft_printf("Simple input test\n"));
	fflush(stdout);
	ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j)); //T2
	fflush(stdout);
}


// Credit to mazoise for those tests, check out her testers ! https://github.com/Mazoise/42TESTERS-PRINTF
void	mazoise(int arg)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	switch (arg)
	{
	case 1:
		T_PRINTF("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d);
		break;
	case 2:
		ft_printf(" --- Return : %d\n", ft_printf("Simple input test\n"));
		fflush(stdout);
		ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j)); //T2
		fflush(stdout);
		break;
	//case 138:
		//T_PRINTF("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", i, j, k, l, m, c, e, d);
		break;
	case 3:
		T_PRINTF("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
		break;
	case 4:
		T_PRINTF("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		break;
	case 5:
		T_PRINTF("%*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j);
	case 6:
		T_PRINTF("%*u, %*x, %*X, %*u,", a, i, a, i, a, i, a, j, a, j);
		break;
	case 7:
		T_PRINTF("%*u, %*x, %*X, %*u,", a, i, a, i, a, i, a, j, a, j);
		break;	
	default:
		break;
	}

}

void	test20(void)
{
	tst_printf("%0*.*i", 1, 3, -12);
}


void	all_tests(void)
{
	solo_int(50);
	test1();
	for (size_t i = 0; i <= 7; i++)
		mazoise(i);
	T_PRINTF("%1.1i", 0);
	T_PRINTF("%2.1i", 0);
	T_PRINTF("%0*.*i", 1, 3, -1);
	T_PRINTF("%0*.*u", 3, 0, 1);
	T_PRINTF("%0*i", 2, 8);
	T_PRINTF("%0*d", 2, 0);
	T_PRINTF("%.*d", -3, -1);
	T_PRINTF("%0*.*d", 3, -2, -1);
	T_PRINTF("%0*d", 3, -1);
	T_PRINTF("%*X", -4, 8);
	T_PRINTF("%*u, %*x, %*X", -4, 8, -4, 8, -4, 8);
	T_PRINTF("%-20.15.23.12.10i", 1234567, 8);
	T_PRINTF("bonjour%10d", 3);
	test1();
	test2();
	test3();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
	test18();
	test19();
	hello_world();
	mazoise_2();
}

/*
**	T_PRINTF is the variadic macro that will compare your ft_printf with the real printf
**	SYNTAX : T_PRINTF(char *format, ...); (just like printf)
*/

int main(int argc, char **argv)
{
	T_PRINTF("%d", 3)
	system("leaks tester.out");
	return (0);
}