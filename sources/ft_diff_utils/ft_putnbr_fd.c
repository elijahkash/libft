/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:22:00 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:11 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

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
