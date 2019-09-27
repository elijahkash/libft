/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:53:49 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 13:39:20 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	print_hex(char c)
{
	if (c < 10)
		ft_putchar('0' + c);
	else
		ft_putchar('a' + c - 10);
}

static void	print_byte(const void *ptr)
{
	print_hex((*(unsigned char *)ptr >> 4) % 16);
	print_hex((*(unsigned char *)ptr << 4 >> 4) % 16);
}

static void	print_str(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ft_isprint(str[i]))
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t	i;
	int		j;
	int		sp;

	sp = 40;
	i = 0;
	while (i < size)
	{
		print_byte((void *)((unsigned char *)addr + i++ + (sp -= 2) * 0));
		if (i % 2 == 0)
			ft_putchar(' ' + (sp-- * 0));
		if (i % 16 == 0)
		{
			print_str((char *)addr + i - 16, 16);
			ft_putchar('\n' + (sp = 40) * 0);
		}
	}
	if (i % 16 != 0)
	{
		j = 0;
		while (j++ < sp)
			ft_putchar(' ');
		print_str((char *)addr + i - i % 16, i % 16);
		ft_putchar('\n');
	}
}
