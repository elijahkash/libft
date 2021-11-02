/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_diff_utils.h"

#include "libft.h"

#include <stdio.h>

static void	print_hex(char c)
{
	(c < 10) ? printf("%c", ('0' + c)) :
				printf("%c", ('a' + c - 10));
}

static void	print_byte(const void *ptr)
{
	print_hex((*(unsigned char *)ptr >> 4) % 16);
	print_hex((*(unsigned char *)ptr << 4 >> 4) % 16);
}

static void	print_str(char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
		(ft_isprint(str[i])) ? printf("%c", str[i]) :
								printf(".");
	printf("\n");
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t	i;
	int		sp;

	sp = 40;
	i = 0;
	while (i < size)
	{
		print_byte((void *)((unsigned char *)addr + i++));
		sp -= 2;
		(i % 2 == 0) ? printf("%c", ' ' + (sp-- * 0)) : 0;
		if (i % 16 == 0)
		{
			print_str((char *)addr + i - 16, 16);
			sp = 40;
		}
	}
	if (i % 16 != 0)
	{
		printf("%*s", sp, "");
		print_str((char *)addr + i - i % 16, i % 16);
	}
}
