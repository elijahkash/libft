/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:53:49 by exam              #+#    #+#             */
/*   Updated: 2019/09/26 13:39:44 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <string.h>



#include <libft.h>

void	print_hex(char c)
{
	if (c < 10)
		ft_putchar('0' + c);
	else
		ft_putchar('a' + c - 10);
}

void	print_byte(const void *ptr)
{
	print_hex((*(unsigned char *)ptr >> 4) % 16);
	print_hex((*(unsigned char *)ptr << 4 >> 4) % 16);
}

int		is_print(char c)
{
	if (c >= 32 && c <= '~')
		return (1);
	return (0);
}

void	print_str(char *str, int size)
{
	int i = 0;

	while (i < size)
	{
		if (is_print(str[i]))
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0;
	int j;
	int sp;

	sp = 40;
	while (i < size)
	{
		print_byte((void *)((unsigned char *)addr + i));
		sp -=2;
		i++;
		if (i % 2 == 0)
		{
			ft_putchar(' ');
			sp--;
		}
		if (i % 16 == 0)
		{
			print_str((char *)addr + i - 16, 16);
			ft_putchar('\n');
			sp = 40;
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

	return ;
}

