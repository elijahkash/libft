/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_opsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:45:08 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:45 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

int				isgreateq_abs_bignum(t_bignum a, t_bignum b, int sdvig_b)
{
	int i;

	i = a.maxsize - 1 - sdvig_b;
	while (i >= 0)
	{
		if (a.number[i + sdvig_b] > b.number[i])
			return (1);
		if (a.number[i + sdvig_b] < b.number[i])
			return (0);
		i--;
	}
	return (1);
}

t_bignum		sub_abs(t_bignum a, t_bignum b, int sdvig_b)
{
	int			i;
	t_bignum	res;

	initialize_bignum(&res, a.maxsize);
	i = 0;
	while (i < sdvig_b - 1)
	{
		res.number[i] = a.number[i];
		i++;
	}
	i = sdvig_b;
	while (i < a.maxsize)
	{
		res.number[i] = a.number[i] - b.number[i - sdvig_b];
		i++;
	}
	fixdown_bignum(&res);
	return (res);
}

t_bignum		ft_div_bignum(t_bignum a, t_bignum b)
{
	int			sdvig_b;
	t_bignum	res;

	initialize_bignum(&res, a.maxsize);
	res.sign = a.sign * b.sign;
	sdvig_b = a.size - b.size;
	while (sdvig_b >= 0)
	{
		while (isgreateq_abs_bignum(a, b, sdvig_b))
		{
			a = sub_abs(a, b, sdvig_b);
			res.number[sdvig_b] += 1;
		}
		sdvig_b--;
	}
	fixup_bignum(&res);
	return (res);
}
