/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:31:16 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/30 04:30:46 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "double.h"

void			reformat_output(char *output, int prec)
{
	char *c;

	c = ft_strchr(output, '.');
	if (prec == 0)
	{
		if (*c != '\0')
			*c = '\0';
		return ;
	}
	if (*c != '\0')
	{
		while (prec-- >= 0 && *c != '\0')
			c++;
		if (*c != '\0')
			*c = '\0';
		else
		{
			prec++;
			while (prec-- >= 0)
				ft_strcat(output, "0");
		}
	}
	else
	{
		ft_strcat(output, ".");
		putnzeros(output, prec);
	}
}

void 			put_bn_output(t_bignum res, char *output, int prec)
{
	int i;

	if (res.sign == -1)
		ft_strcat(output, "-");
	if (res.size == 0)
	{
		ft_strcat(output, "0");
		return;
	}
	//дальнейшее условие - это печать целой части и первого элемента, где целая часть соединяется с дробной.
	if (res.size - 1 <= (res.exp - 1) / 4)
	{
		i = (res.exp - 1) / 4;
		ft_strcatnbr(output, res.number[(res.exp - 1) / 4] / ft_pow_bn(10, (res.exp - 1) % 4 + 1));
	}
	else
	{
		ft_strcatnbr(output, res.number[res.size - 1]);
		i = res.size - 2;
		while (i > (res.exp - 1) / 4)
		{
			ft_strcatnbr_wzeros(output, res.number[i], 4);
			i--;
		}
		if (3 - (res.exp - 1) % 4 > 0)
			ft_strcatnbr_wzeros(output,
								res.number[i] / ft_pow_bn(10, (res.exp - 1) % 4 + 1),
								3 - (res.exp - 1) % 4);
	}
	ft_strcat(output, ".");
	ft_strcatnbr_wzeros(output,
						res.number[(res.exp - 1) / 4] % ft_pow_bn(10, (res.exp - 1) % 4 + 1),
						(res.exp - 1) % 4 + 1);
	i--;
	while (i >= 0)
		ft_strcatnbr_wzeros(output, res.number[i--], 4);

	reformat_output(output, prec);
	// (res.exp - 1) % 4 + 1 - размер дробной части
	// 3 - (res.exp - 1) % 4 - размер целой части
	// res.number[(res.exp - 1) / 4] % ft_pow_bn(10, (res.exp - 1) % 4 + 1) - это дробная часть
	// res.number[(res.exp - 1) / 4] / ft_pow_bn(10, (res.exp - 1) % 4 + 1) - это целая часть

}
