/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_tester.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:15:24 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/01 21:05:12 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_TESTER_H
# define PTF_TESTER_H

# include "../../libftprintf.h"

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# define T_PRINTF(f_, ...) {\
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

# define T_NO_ARG_PRINTF(f_) {\
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

void    test_fast_correction(void);
void    diff_fast_correction(int (*printer)(char *, ...));
void	test1(void);
void	test2(void);
void	test3(void);
void	test4(void);
void	test5(void);
void	test6(void);
void	test7(void);
void	test8(void);
void	test9(void);
void	test10(void);
void	test11(void);
void 	test12(void);
void 	test13(void);
void 	test14(void);
void	test15(void);
void 	hello_world(void);
void	mazoise(int arg);

#endif