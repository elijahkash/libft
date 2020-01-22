/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:53:49 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/22 21:41:10 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <libft.h>

static void	print_hex(char c)
{
	(c < 10) ? ft_printf("%c", ('0' + c)) :
				ft_printf("%c", ('a' + c - 10));
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
		(ft_isprint(str[i])) ? ft_printf("%c", str[i]) :
								ft_printf(".");
	ft_printf("\n");
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
		(i % 2 == 0) ? ft_printf("%c", ' ' + (sp-- * 0)) : 0;
		if (i % 16 == 0)
		{
			print_str((char *)addr + i - 16, 16);
			sp = 40;
		}
	}
	if (i % 16 != 0)
	{
		ft_printf("%*s", sp, "");
		print_str((char *)addr + i - i % 16, i % 16);
	}
}
