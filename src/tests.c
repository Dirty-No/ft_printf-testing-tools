/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:30:54 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/01 21:21:09 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_tester.h"

/*
**  This function is meant to be used with the diff test
**  It follows the (old) official correction's instructions (if you have a copy of the new one please to send it to me at smaccary@student.42.fr)
**  If your ft_printf passes this test, it should pass the moulinette. (Do not forget to check memory leaks on your own tho)
**  This doesn't test anything undefined or nonsensical (like %p convertion with 0 padding or precision) since it's purpose is to be used for corrections.
**  /!\ DO NOT FORGET THAT %p CONVERTION DOES NOT BEHAVES THE SAME ON MACOS AND LINUX (especially for NULL pointer) /!\ 
*/

void    diff_fast_correction(int (*printer)(char *, ...))
{
    void *ptr = malloc(1);

/*
** 'printer' function is either your system's printf or your ft_printf. (See test_diff.c)
*/

/*  Simple Tests (these titles are from the official corrections)
**      - Check that the usual conversions %s, %p and %d works fine
**      - Check that %% works
*/
   
    printer("%s\n", "Simple Tests");
    printer("%s\n", NULL);
    printer("%p\n", ptr);
    printer("%p\n", NULL);
    printer("%d\n", 1234);
    printer("%d\n", INT_MAX);
    printer("%d\n", INT_MIN);
    printer("%%\n");

/*
** Less simples Tests
** Check that you can put multiple conversions
** (and so multiple arguments) of the same type in a same printf
*/
    
    printer("%s %s %s %s %s\n", NULL, "string 1\\", "string 2\\", "string 3\\", "string 4\\");
    printer("%p %p %p %p\n", ptr, NULL, (void *)500, 32);
    printer("%d %d %d %d\n", 1234, INT_MAX, INT_MAX, 0);

/*  Slightly complicated tests
**  Check that the less usual conversions %i, %u, %x, %X and %c work fine
*/
    
    printer("%i %u %x %X %c\n", (int)'a', (unsigned int)'b',\
            (unsigned int)'c', (unsigned int)'d', 'e');
    
/*
**  Complicated tests
**  Check that multiple conversions and parameters of
**  differents sizes are all working properly and in different orders
*/
    
    printer("%s %p %d %i %x %c %p %s\n", "Complicated tests", ptr, 1234, 4, 8, 'o', NULL, NULL);

/*
**  More complicated tests
**  Check the flags: * , 0, -, ., and the field width 
*/
    printer("%10s %1p %104d %12i %x %-100c %10p %-52s\n", "More complicated tests : here's some random format in a string :%d %s %p %c %i ",\
            ptr, 1234, 4, 8, 'o', NULL, NULL);
    printer("%s %*d\n", "%s %s %10s %10d", 10, 10);
    printer("%13.5d %*.*i %40.*s\n", INT_MAX, 13, 4, INT_MIN, 31, "precision & padding string test | this should not be displayed");   
    printer("%020d\n", INT_MIN);
    printer("%0*d\n", 20, INT_MIN);
    printer("%0*i\n", 20, INT_MIN);
    printer("%0*d\n", -20, -50);
    printer("%0*.*d\n", -30, 25, INT_MIN);
    printer("%.s\n", ". flag string test");
    if (ptr)
        free(ptr);
}

/*
**  Same function for manual tests.
*/

void    test_fast_correction(void)
{
    void *ptr = malloc(1);

/*  Simple Tests
**      - Check that the usual conversions %s, %p and %d works fine
**      - Check that %% works
*/
   
    T_PRINTF("%s", "Simple Tests");
    T_PRINTF("%s", NULL);
    T_PRINTF("%p", ptr);
    T_PRINTF("%p", NULL);
    T_PRINTF("%d", 1234);
    T_PRINTF("%d", INT_MAX);
    T_PRINTF("%d", INT_MIN);
    T_NO_ARG_PRINTF("%%");

/*
**  Less simples Tests
**  Check that you can put multiple conversions
**  (and so multiple arguments) of the same type in a same printf
*/
    
    T_PRINTF("%s %s %s %s %s", NULL, "string 1\\", "string 2\\", "string 3\\", "string 4\\");
    T_PRINTF("%p %p %p %p", ptr, NULL, (void *)500, &ft_printf);
    T_PRINTF("%d %d %d %d", 1234, INT_MAX, INT_MAX, 0);

/*  Slightly complicated tests
**  Check that the less usual conversions %i, %u, %x, %X and %c work fine
*/
    
    T_PRINTF("%i %u %x %X %c", (int)'a', (unsigned int)'b',\
            (unsigned int)'c', (unsigned int)'d', 'e');
    
/*
**  Complicated tests
**  Check that multiple conversions and parameters of
**  differents sizes are all working properly and in different orders
*/
    
    T_PRINTF("%s %p %d %i %x %c %p %s", "Complicated tests", ptr, 1234, 4, 8, 'o', NULL, NULL);

/*
**  More complicated tests
**  Check the flags: * , 0, -, ., and the field width 
*/

    T_PRINTF("%10s %1p %104d %12i %x %-100c %10p %-52s", "More complicated tests : here's some random format in a string :%d %s %p %c %i ",\
            ptr, 1234, 4, 8, 'o', NULL, NULL);
    T_PRINTF("%s %*d", "%s %s %10s %10d", 10, 10);
    T_PRINTF("%13.5d %*.*i %40.*s", INT_MAX, 13, 4, INT_MIN, 31, "precision & padding string test | this should not be displayed");   
    T_PRINTF("%020d", INT_MIN);
    T_PRINTF("%0*d", 20, INT_MIN);
    T_PRINTF("%0*i", 20, INT_MIN);
    T_PRINTF("%0*d", -20, -50);
    T_PRINTF("%0*.*d", -30, 25, INT_MIN);
    T_PRINTF("%.s", ". flag string test");
    if (ptr)
        free(ptr);
}


/*
** These are old tests I made back when I was still working on ft_printf, all of these are defined cases so you can use them or just look for ideas for you own tests as you want.
** They do not look nearly as good as tests made with T_PRINTF() tho.
*/

void	test1(void)
{
	char	*ptr = malloc(1);
	char 	str[]= "\nyeeet |%%| |%c| |%d| |%p| |%X| |%s| \\|%s|\\ \
Je suis actuellement en train de manger du pain--d- \
|%6d| |%-03d|_|%%| |%00*d| |%15.10d| |%-15.10d| |%15.1d|\n";

	ft_printf("\nft_printf (%d)\n", ft_printf(str, 'P', 3, ptr, 756,
			   	"This is a test string", NULL, 500,
			   	9, 10, 7777, 123456789, -123456789, 123456789));

	printf("\nprintf (%d) \n", printf(str, 'P', 3, ptr, 756,
			   	"This is a test string", NULL, 500,
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

void	test4(void)
{
	int		nb1;
	int		nb2;
	char 	str[]= "\nyeeet |%%| |%c| |%d| |%p| |%X| |%s| \\|%s|\\ Je suis actuellement en train de manger du pain--d- |%6d| |%-03d|_|%%| |%00*d|\n";
	char	*ptr = malloc(1);

	nb1 = printf(str, 'P', 3, ptr, 756, "This is a test string", NULL, 500, 9, 10, 7777);
	fflush(stdout);
	nb2 = ft_printf(str, 'P', 3, ptr, 756, "This is a test string", NULL, 500, 9, 10, 7777);
	printf("%d|%d\n", nb1, nb2);	

	ft_printf(str, 'P', 3, ptr, 756, "This is a test string", NULL, 500, 9, 10, 7777);
	//printf(str, 'P', 3, ptr, 756, "This is a test string", NULL, 500, 9, 10, 7777);
	free(ptr);
}

void	test5(void)
{
	int		nb1;
	int		nb2;

	nb1 = printf("Bonjour\n");
	nb2 = ft_printf("Bonjour\n");
	printf("%d|%d\n", nb1, nb2);
}

void	test6(void)
{
	int		nb1;
	int		nb2;
	char	str[]= "|%15.10d|\n";

	nb1 = printf(str, -1234567);
	nb2 = ft_printf(str, -1234567);
	printf("%d|%d\n", nb1, nb2);
}

void	test7(void)
{
	//minimal field width + precision with ints
	int		nb1;
	int		nb2;
	char	str[]= "|%-15.10d|\n";

	nb1 = printf(str, -1234567);
	nb2 = ft_printf(str, -1234567);
	printf("%d|%d\n", nb1, nb2);
}

void	test8(void)
{
	//ONLY PRECISION WITH NUMBERS
	int		nb1;
	int		nb2;
	char	str[]= "|%.20p| |%.20x| |%.20X|\n";

	nb1 = printf(str, (char *)-50, -50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}


void	test9(void)
{
	//minimal field width + precision with ints POSITIVE
	int		nb1;
	int		nb2;
	char	str[]= "|%15.10d|\n";

	nb1 = printf(str, 1234567);
	nb2 = ft_printf(str, 1234567);
	printf("%d|%d\n", nb1, nb2);
}

void	test10(void)
{
	//minimal field width + precision with chars
	int		nb1;
	int		nb2;
	char	str[]= "|%015.10c| |%015c|\n";

	nb1 = printf(str, 'O', 'O');
	nb2 = ft_printf(str, 'O', 'O');
	printf("%d|%d\n", nb1, nb2);
}

void	test11(void)
{
	//minimal field width + LOW precision with ints POSITIVE
	int		nb1;
	int		nb2;
	char	str[]= "|%15.2X|\n";

	nb1 = printf(str, 1234567);
	nb2 = ft_printf(str, 1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test12(void)
{
	//minimal field width + LOW precision with unsigned hex int + int
	int		nb1;
	int		nb2;
	char	str[]= "|%15.1p|\t|%15.11d|\n";

	nb1 = printf(str, 1234567, 1234567);
	nb2 = ft_printf(str, 1234567, 1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test13(void)
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

void test14(void)
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
	T_NO_ARG_PRINTF("|Hello World!|");
}

void	solo_int(int nb)
{
	T_PRINTF("|%d|", nb);
}


// mazoise made those tests, i blatantly stole them from her, check out her testers https://github.com/Mazoise/42TESTERS-PRINTF
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

void	test15(void)
{
	T_PRINTF("%0*.*i", 1, 3, -12);
}
