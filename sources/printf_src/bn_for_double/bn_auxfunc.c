/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_auxfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:50:43 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:48 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

#include <libft.h>

int				ft_pow_bn(int num, unsigned int p)
{
	unsigned int	i;
	int				tmp;

	if (p == 0)
		return (1);
	tmp = num;
	i = 0;
	while (++i < p)
		num = num * tmp;
	return (num);
}

void			ft_intpart(int pow, unsigned long int mant,
							int exp, t_bigdec *bd)
{
	t_bignum	mult;
	t_bignum	*res;

	res = &(bd->intpart);
	if (exp <= 0)
		return ;
	ft_assign_bignum(&mult, res->maxsize, 2);
	ft_ipow_small_bignum(&mult, 2, pow);
	while (mant > 0)
	{
		if (mant & 1)
			ft_isumabs_bignum(res, mult);
		mant >>= 1;
		ft_imul_small_bignum(&mult, 2);
	}
}

void			ft_fractpart(int pow, unsigned long int mant, t_bigdec *bd)
{
	int			i;
	t_bignum	five;
	t_bignum	two;
	t_bignum	*res;

	res = &(bd->fractpart);
	ft_assign_bignum(res, res->maxsize, 0);
	ft_assign_bignum(&five, res->maxsize, 5);
	ft_ipow_small_bignum(&five, 5, 64 + pow);
	if (pow == 0)
		ft_assign_bignum(&two, res->maxsize, 1);
	else
		ft_assign_bignum(&two, res->maxsize, 2);
	i = 0;
	while (++i <= 64)
	{
		if (mant & 0x0000000000000001)
			ft_isumabs_bignum(res, two);
		mant >>= 1;
		ft_imul_small_bignum(&two, 2);
	}
	ft_imul_bignum(res, five);
	bd->sizefract = 64 + pow;
}
