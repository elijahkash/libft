/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_opsummul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:46:29 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:43 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

void			ft_isumabs_bignum(t_bignum *res, t_bignum bn2)
{
	int			i;
	int			maxsize;
	int			div;

	maxsize = res->size > bn2.size ? res->size : bn2.size;
	div = 0;
	i = 0;
	while (i < maxsize)
	{
		res->number[i] += bn2.number[i] + div;
		div = res->number[i] / BASE_BN;
		res->number[i] %= BASE_BN;
		i++;
	}
	if (div != 0)
	{
		res->number[i] = div;
		res->size = maxsize + 1;
	}
	else
		res->size = maxsize;
}

void			ft_imul_bignum(t_bignum *res, t_bignum bn2)
{
	int			i;
	int			j;
	t_bignum	temp_bn;

	initialize_bignum(&temp_bn, res->maxsize);
	i = 0;
	while (i < temp_bn.maxsize)
	{
		j = 0;
		while (j < temp_bn.maxsize - i)
		{
			temp_bn.number[i + j] += res->number[i] * bn2.number[j];
			j++;
		}
		i++;
	}
	temp_bn.sign = res->sign * bn2.sign;
	temp_bn.exp = res->exp;
	fixup_bignum(&temp_bn);
	fixsize_bignum(&temp_bn);
	ft_deepcopy_bignum(res, temp_bn);
}

void			ft_imul_small_bignum(t_bignum *res, unsigned int n)
{
	long int	div;
	int			i;
	long int	tmp;
	t_bignum	temp_bn;

	if (n / 100 != 0)
	{
		ft_assign_bignum(&temp_bn, res->maxsize, n);
		ft_imul_bignum(res, temp_bn);
		return ;
	}
	div = 0;
	i = 0;
	while (i < res->size)
	{
		tmp = res->number[i] * (long int)n + div;
		res->number[i] = tmp % BASE_BN;
		div = tmp / BASE_BN;
		i++;
	}
	if (div != 0)
	{
		res->number[i] = div;
		res->size++;
	}
}

t_bignum		ft_mul_bignum(t_bignum bn1, t_bignum bn2)
{
	int			i;
	int			j;
	t_bignum	res_bn;

	initialize_bignum(&res_bn, bn1.maxsize);
	i = 0;
	while (i < res_bn.maxsize)
	{
		j = 0;
		while (j < res_bn.maxsize - i)
		{
			res_bn.number[i + j] += bn1.number[i] * bn2.number[j];
			j++;
		}
		i++;
	}
	res_bn.sign = bn1.sign * bn2.sign;
	fixup_bignum(&res_bn);
	fixsize_bignum(&res_bn);
	return (res_bn);
}
