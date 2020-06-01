/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:39:45 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/01 21:21:33 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_tester.h"

/* 
**	This program is meant to be used with diff_it.sh bash script.
**	diff_it.sh will compile & run this program with ft_printf before running it with the real printf, and will diff their output.
**	You can add any test you want using the "printer" function pointer as printf / ft_printf.
*/

int main(int argc, char **argv)
{
// You can change format and arguments as you want
	char format[] = "Lorem ipsum dolor sit amet, |%10.1d| consectetur adipiscing elit. Maecenas vestibulum ultricies eros sed |%5s| \
	dignissim. Vivamus tempor velit in lectus maximus interdum. Morbi iaculis dignissim nunc. Pellentesque tincidunt arcu a\
	dui porta, |%5c| nec imperdiet justo tincidunt. Sed vitae leo pretium, ultrices justo id, scelerisque lacus. Pellentesque\
	habitant morbi tristique senectus et netus et males |%i| uada fames ac turpis egestas. Phasellus tristique lobortis leo. Maecenas bibendum\
	pulvinar diam ac fermentum. Integer vel mauris vitae nisl maximus porta. Nunc a eros quam. Etiam finibus ante non purus imperdiet consectetur.\
		Suspendisse sed lacus leo. Phasellus ornare dui eu quam posuere, at elementum odio mollis. Vivamus eget facilisis eros. Vivamus maximus ac quam\
		at placerat. Vestibulum nec tincid |%s| unt quam.";
	int (*printer)(char *, ...);

	printer = (argc >= 2) ? &printf : &ft_printf;

// Write your tests here

	//printer(format, INT_MAX, format, 'P', INT_MIN, format);
	diff_fast_correction(printer); // Default unit test.
	return (0);
}
