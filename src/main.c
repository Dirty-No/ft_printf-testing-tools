/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:34:06 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/01 14:31:18 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ptf_tester.h"

static void	all_tests(void)
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
	hello_world();
	mazoise_2();
}

/*
**	T_PRINTF is the variadic macro that will compare your ft_printf with the real printf
**	SYNTAX : T_PRINTF(char *format, ...); (just like printf)
*/

int	main(int argc, char **argv)
{
	//all_tests();
	T_PRINTF("%d", 3)
	system("leaks tester.out");
	return (0);
}