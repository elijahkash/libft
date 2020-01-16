/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:52:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:42 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

#include <libft.h>

void			ft_put_one_inpos_bignum(t_bignum *bn, int maxsize, int pos)
{
	initialize_bignum(bn, maxsize);
	bn->number[(pos - 1) / 4] = ft_pow_bn(10, (pos - 1) % 4);
	bn->size = (pos - 1) / 4 + 1;
	bn->sign = 1;
}

int				ft_get_inpos_bignum(t_bignum bn, int pos)
{
	int tmp;

	if (pos <= 0)
		return (0);
	tmp = bn.number[(pos - 1) / 4] / ft_pow_bn(10, (pos - 1) % 4);
	return (tmp % 10);
}

static void		zeroafterround(t_bignum *res, int pos)
{
	int i;
	int ten;

	i = 0;
	while (i < (pos - 1) / 4)
	{
		res->number[i] = 0;
		i++;
	}
	ten = ft_pow_bn(10, (pos - 1) % 4 + 1);
	res->number[(pos - 1) / 4] -= res->number[(pos - 1) / 4] % ten;
}

void			normalize_bn(t_bignum *res)
{
	int len_res;

	if (res->size == 0)
		len_res = 0;
	else if (res->size == 1)
		len_res = ft_nbrlen(res->number[0]);
	else
		len_res = (res->size - 1) * 4 + ft_nbrlen(res->number[res->size - 1]);
	if (len_res == 0)
		res->normalexp = 0;
	else
	{
		res->normalexp = len_res - res->exp - 1;
		res->exp += res->normalexp;
	}
}

void			round_bn(t_bignum *res, int prec)
{
	t_bignum	ten;

	if (res->exp - prec < 0)
		return ;
	else
	{
		if (ft_get_inpos_bignum(*res, res->exp - prec) == 5)
		{
			if (is_last_five(*res, res->exp - prec) == 0 ||
				ft_get_inpos_bignum(*res, res->exp - prec + 1) % 2 == 1)
			{
				ft_put_one_inpos_bignum(&ten, res->maxsize,
										res->exp - prec + 1);
				ft_isumabs_bignum(res, ten);
			}
		}
		else if (ft_get_inpos_bignum(*res, res->exp - prec) > 5)
		{
			ft_put_one_inpos_bignum(&ten, res->maxsize, res->exp - prec + 1);
			ft_isumabs_bignum(res, ten);
		}
		zeroafterround(res, res->exp - prec);
	}
}
