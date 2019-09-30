#include "libft.h"
#include "double.h"

void	ft_intpart(int pow, unsigned long int mant, int exp, t_bigdec *bd)
{
	t_bignum	mult;
	t_bignum	*res;

	res = &(bd->intpart);
	if (exp <= 0)
		return ;
	ft_assign_bignum(&mult, res->maxsize, 2);
	ft_ipow_bignum(&mult, pow);
	while (mant > 0)
	{
		if (mant & 1)
			ft_isumabs_bignum(res, mult);
		mant >>= 1;
		ft_isumabs_bignum(&mult, mult);
	}
}

void 	ft_fractpart(int pow, unsigned long int mant, char *output, t_bigdec *bd)
{
	int		i;
	t_bignum	five;
	t_bignum	two;
	t_bignum	*res;

	res = &(bd->fractpart);

	ft_assign_bignum(res, res->maxsize, 0);
	ft_assign_bignum(&five, res->maxsize, 5);
	ft_assign_bignum(&two, res->maxsize, 2);
	ft_ipow_bignum(&five, 64 + pow);
	i = 0;
	while (++i <= 64)
	{
		if (mant &0x8000000000000000)
			ft_isumabs_bignum(res, ft_mul_bignum(five, ft_pow_bignum(two, 64 - i + (pow == 0 ? 0 : 1))));
		mant <<= 1;
	}
	bd->sizefract = 64 + pow;
}

int		check_specvalues(union u_double d, char *output)
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
			reformat_output(output, prec);
		}
	}
	return (1);
}

void 	makebnwithfract(t_bignum *res, t_bigdec bd)
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


int		countmaxsize(exp)
{
	if (exp < 600)
		return (100);
	else if (exp < 1200)
		return (200);
	else if (exp < 2400)
		return (300);
	else if (exp < 3600)
		return (400);
	else if (exp < 6000)
		return (600);
	else if (exp < 12000)
		return (1100);
	else
		return (1300);

}


int 	ft_itoa_f(union u_double d, char *output, int prec)
{
	int 				exp;
	int 				pow;
	unsigned long int	mant;
	t_bigdec			bd;
	t_bignum			res;

	if (check_specvalues(d, output))
		return (1);
	else
	{
		pow = 0;
		exp = (d.s_parts.e == 0) ? 0 : d.s_parts.e - 16382;
		if (exp > 0 && exp < 65)
			mant = d.s_parts.m >> (64 - exp);
		else
		{
			pow = (exp <= 0) ? -exp + 1 : exp - 64;
			mant = d.s_parts.m;
		}
		initialize_bd(&bd, countmaxsize(exp));
		bd.sign = d.s_parts.s == 1 ? -1 : 1;
		ft_intpart(pow, mant, exp, &bd);
		if (exp <= 65)
			ft_fractpart(pow, exp <= 0 ? d.s_parts.m : d.s_parts.m << exp, output, &bd);
		makebnwithfract(&res, bd);
		round_bn(&res, prec);
		put_bn_output(res, output, prec);
	}
}
