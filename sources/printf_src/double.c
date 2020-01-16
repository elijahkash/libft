/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:58:03 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

#include <libft.h>

static int	check_specvalues(union u_double d, char *output,
							t_specifications_def spec)
{
	if (!((d.ld != d.ld || d.ld == 1.0 / 0.0 || d.ld == -1.0 / 0.0 ||
		(d.s_parts.e == 0 && d.s_parts.m == 0))))
		return (0);
	else
	{
		if (d.ld != d.ld)
			ft_strcat(output, (spec.spec == 15) ? "NAN" : "nan");
		else if (d.ld == 1.0 / 0.0)
			ft_strcat(output, (spec.spec == 15) ? "INF" : "inf");
		else if (d.ld == -1.0 / 0.0)
			ft_strcat(output, (spec.spec == 15) ? "-INF" : "-inf");
		else if (d.s_parts.e == 0 && d.s_parts.m == 0)
		{
			if (d.s_parts.s == 1)
				ft_strcat(output, "-0");
			else
				ft_strcat(output, "0");
			reformat_output(output, spec);
			if (spec.spec == 14 || spec.spec == 15)
				ft_strcat(output, (spec.spec == 14) ? "e+00" : "E+00");
		}
	}
	return (1);
}

static void	count_parts_d(union u_double d, int *pow, int *exp,
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

static void	workwithspec(t_bignum *res, char *output, t_specifications_def spec)
{
	if (spec.spec == 12)
	{
		round_bn(res, spec.precision);
		put_bn_output(*res, output, spec);
	}
	if (spec.spec == 14 || spec.spec == 15)
	{
		normalize_bn(res);
		round_bn(res, spec.precision);
		put_bn_output(*res, output, spec);
		if (res->normalexp < 0)
			ft_strcat(output, (spec.spec == 14) ? "e" : "E");
		else
			ft_strcat(output, (spec.spec == 14) ? "e+" : "E+");
		ft_strcatnbr_wzeros(output, res->normalexp, 2);
	}
}

void		ft_itoa_f(union u_double d, char *output, t_specifications_def spec)
{
	int					exp;
	int					pow;
	unsigned long int	mant;
	t_bigdec			bd;
	t_bignum			res;

	if (check_specvalues(d, output, spec))
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
		workwithspec(&res, output, spec);
	}
}
