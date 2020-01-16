/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_fix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:41:50 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:47 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

void			fixsize_bignum(t_bignum *bn)
{
	int i;

	i = bn->maxsize - 1;
	while (i >= 0)
	{
		if (bn->number[i] != 0)
			break ;
		i--;
	}
	bn->size = i + 1;
}

void			fixup_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while (i < bn->maxsize - 1)
	{
		bn->number[i + 1] += bn->number[i] / BASE_BN;
		bn->number[i] = bn->number[i] % BASE_BN;
		i++;
	}
	fixzero_bignum(bn);
}

void			fixzero_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while (i < bn->maxsize)
	{
		if (bn->number[i] != 0)
			return ;
		i++;
	}
	bn->size = 0;
}

void			fixdown_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while (i < bn->maxsize - 1)
	{
		while (bn->number[i] < 0)
		{
			bn->number[i] += BASE_BN;
			bn->number[i + 1] -= 1;
		}
		i++;
	}
	fixzero_bignum(bn);
	fixsize_bignum(bn);
}

void			makebnwithfract(t_bignum *res, t_bigdec bd)
{
	t_bignum ten;

	ft_deepcopy_bignum(res, bd.intpart);
	res->exp = bd.sizefract;
	res->sign = bd.sign;
	if (bd.sizefract != 0)
	{
		ft_put_one_inpos_bignum(&ten, res->maxsize, bd.sizefract + 1);
		ft_imul_bignum(res, ten);
		ft_isumabs_bignum(res, bd.fractpart);
	}
}
