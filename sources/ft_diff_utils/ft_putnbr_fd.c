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

void	ft_putnbr_fd(int n, int fd)
{
	long long int	src_number;
	int				count_n;

	src_number = n;
	count_n = 1;
	if (src_number < 0)
	{
		ft_putchar_fd('-', fd);
		src_number *= -1;
	}
	while (n / 10 != 0)
	{
		count_n *= 10;
		n /= 10;
	}
	if (src_number == 0)
		ft_putchar_fd('0', fd);
	else
		while (count_n > 0)
		{
			ft_putchar_fd(src_number / count_n + 48, fd);
			src_number %= count_n;
			count_n /= 10;
		}
	return ;
}
