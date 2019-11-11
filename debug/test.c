/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/11 19:28:07 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <math.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <float.h>

void	f(uint64_t n)
{
	ft_print_memory(&n, sizeof(uint64_t));
}

int		main(void)
{
	ft_gc_init();

	uint64_t test;
	uint64_t res;

	test = 1LLU << 61;

	f(test);
	ft_printf("\n%.64llb\n", test);
	asm("bsrq\t%1, %0" : "=r" (res) , "+rm" (test));
	ft_printf("%lld\n", res);


	ft_printf("\n\n");
	ft_force_buff();
	test = RESETBIT(test, res);

	f(test);
	ft_printf("\n%.64llb\n", test);
	asm("bsrq\t%1, %0" : "=r" (res) , "+rm" (test));
	ft_printf("%lld\n", res);

	ft_force_buff();
	ft_gc_clean();
}
