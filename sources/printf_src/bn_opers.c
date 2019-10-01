/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:46:29 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/01 20:43:09 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

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

void			ft_isumabs_bignum(t_bignum *res, t_bignum bn2)
{
	int			i;
	t_bignum	temp_bn;

	i = 0;
	initialize_bignum(&temp_bn, res->maxsize);
	while (i < temp_bn.maxsize)
	{
		temp_bn.number[i] += res->number[i] + bn2.number[i];
		fixup_bignum(&temp_bn);
		i++;
	}
	fixsize_bignum(&temp_bn);
	temp_bn.sign = res->sign;
	temp_bn.exp = res->exp;
	ft_deepcopy_bignum(res, temp_bn);
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
		tmp = res->number[i] * (long int) n + div;
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

void 			ft_ipow_small_bignum(t_bignum *res, unsigned int n, unsigned int pow)
{
	unsigned int i; //TODO: check it (type)

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
	int i;

	t_bignum res;
	initialize_bignum(&res, a.maxsize);
	i = 0;
	while (i < sdvig_b - 1)
	{
		res.number[i] = a.number[i];
		i++;
	}
	i = sdvig_b;
	while(i < a.maxsize)
	{
		res.number[i] = a.number[i] - b.number[i - sdvig_b];
		i++;
	}
	fixdown_bignum(&res);
	return (res);
}

t_bignum		ft_div_bignum(t_bignum a, t_bignum b)
{
	int sdvig_b;
	t_bignum res;

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
