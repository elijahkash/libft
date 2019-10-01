/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/02 00:03:43 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "double.h"

static void		ft_intpart(int pow, unsigned long int mant,
							int exp, t_bigdec *bd)
{
	t_bignum	mult;
	t_bignum	*res;

	res = &(bd->intpart);
	if (exp <= 0)
		return ;
	ft_assign_bignum(&mult, res->maxsize, 2);
	ft_ipow_small_bignum(&mult, 2, pow);
//	ft_ipow_bignum(&mult, pow);
	while (mant > 0)
	{
		if (mant & 1)
			ft_isumabs_bignum(res, mult);
		mant >>= 1;
		ft_imul_small_bignum(&mult, 2);
	}
}

static void		ft_fractpart(int pow, unsigned long int mant, t_bigdec *bd)
{
	int			i;
	t_bignum	five;
	t_bignum	two;
	t_bignum	*res;

	res = &(bd->fractpart);
	ft_assign_bignum(res, res->maxsize, 0);
	ft_assign_bignum(&five, res->maxsize, 5);
//	ft_assign_bignum(&two, res->maxsize, 2);
	ft_ipow_small_bignum(&five, 5, 64 + pow);
//	i = 0;
//	while (++i <= 64)
//	{
//		if (mant & 0x8000000000000000)
//			ft_isumabs_bignum(res, ft_pow_bignum(two, 64 - i + (pow == 0 ? 0 : 1)));
//		mant <<= 1;
//	}

// для i = 64:
// pow = 0: 64 - 64 + 0 = 0
// pow = 1: 64 - 64 + 1 = 1
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

static int		check_specvalues(union u_double d, char *output, int prec)
{
	if (!((d.ld != d.ld || d.ld == 1.0 / 0.0 || d.ld == -1.0 / 0.0 ||
		(d.s_parts.e == 0 && d.s_parts.m == 0))))
		return (0);
	else
	{
		if (d.ld != d.ld)
			ft_strcat(output, "nan");
		else if (d.ld == 1.0 / 0.0)
			ft_strcat(output, "inf");
		else if (d.ld == -1.0 / 0.0)
			ft_strcat(output, "-inf");
		else if (d.s_parts.e == 0 && d.s_parts.m == 0)
		{
			if (d.s_parts.s == 1)
				ft_strcat(output, "-0");
			else
				ft_strcat(output, "0");
			prec = prec ? prec : 0;
			reformat_output(output, prec);
		}
	}
	return (1);
}

static void		count_parts_d(union u_double d, int *pow, int *exp,
							unsigned long int *mant)
{
	*pow = 0;
	*exp = (d.s_parts.e == 0) ? 0 : d.s_parts.e - 16382;
	if (*exp > 0 && *exp < 65)
		*mant = d.s_parts.m >> (64 - *exp);
	else
	{
		*pow = (*exp <= 0) ? -(*exp) + 1 : (*exp) - 64;
		*mant = d.s_parts.m;
	}
}

void			ft_itoa_f(union u_double d, char *output, int prec, char spec)
{
	int					exp;
	int					pow;
	unsigned long int	mant;
	t_bigdec			bd;
	t_bignum			res;

	if (check_specvalues(d, output, prec))
		return ;
	else
	{
		count_parts_d(d, &pow, &exp, &mant);
		initialize_bd(&bd, countmaxsize_bignum(exp));
		bd.sign = d.s_parts.s == 1 ? -1 : 1;
		ft_intpart(pow, mant, exp, &bd);
		if (exp <= 65)
			ft_fractpart(pow, exp <= 0 ? d.s_parts.m : d.s_parts.m << exp, &bd);
		makebnwithfract(&res, bd);
		if (spec == 'f')
		{
			round_bn(&res, prec);
			put_bn_output(res, output, prec);
		}
		if (spec == 'e')
		{
			normalize_bn(&res);
			round_bn(&res, prec);
			put_bn_output(res, output, prec);
			if (res.normalexp < 0)
				ft_strcat(output, "e");
			else
				ft_strcat(output, "e+");
			ft_strcatnbr_wzeros(output, res.normalexp, 2);

		}
	}
}
