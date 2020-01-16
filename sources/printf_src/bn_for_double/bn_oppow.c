/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_oppow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:45:18 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:45 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

t_bignum		ft_pow_bignum(t_bignum bn, unsigned int n)
{
	unsigned int	i;
	t_bignum		res_bn;

	if (n == 0)
	{
		ft_assign_bignum(&res_bn, bn.maxsize, 1);
		return (res_bn);
	}
	ft_deepcopy_bignum(&res_bn, bn);
	i = 1;
	while (i < n)
	{
		ft_imul_bignum(&res_bn, bn);
		i++;
	}
	res_bn.exp = bn.exp;
	return (res_bn);
}

void			ft_ipow_small_bignum(t_bignum *res, unsigned int n,
									unsigned int pow)
{
	unsigned int i;

	if (pow == 0)
	{
		ft_assign_bignum(res, res->maxsize, 1);
		return ;
	}
	i = 1;
	while (i < pow)
	{
		ft_imul_small_bignum(res, n);
		i++;
	}
}

void			ft_ipow_bignum(t_bignum *res, unsigned int n)
{
	unsigned int	i;
	t_bignum		tmp_bn;

	if (n == 0)
	{
		ft_assign_bignum(res, res->maxsize, 1);
		return ;
	}
	ft_deepcopy_bignum(&tmp_bn, *res);
	i = 1;
	while (i < n)
	{
		ft_imul_bignum(res, tmp_bn);
		i++;
	}
}
