#include "double.h"

void			initialize_bignum(t_bignum *n, int maxsize)
{
	int i;

	n->maxsize = maxsize;
	i = 0;
	while (i < n->maxsize)
	{
		n->number[i] = 0;
		i++;
	}
	n->sign = 0;
	n->size = 0;
	n->exp = 0;
}

void			initialize_bd(t_bigdec *bd, int maxsize)
{
	initialize_bignum(&(bd->intpart), maxsize);
	initialize_bignum(&(bd->fractpart), maxsize);
	bd->sizefract = 0;
	bd->prec = 0;
	bd->sign = 0;
}

void			ft_assign_bignum(t_bignum *bn, int maxsize, long long n)
{
	int i;

	initialize_bignum(bn, maxsize);
	if (n == 0)
		return ;
	bn->sign = (n < 0) ? -1 : 1;

	i = 0;
	if (n < 0)
	{
		bn->number[i++] = -(n % BASE_BN);
		n = -(n / BASE_BN);
	}
	while (n != 0)
	{
		bn->number[i++] = (int)(n % BASE_BN);
		n = n / BASE_BN;
	}
	bn->size = i;
}

void 			ft_deepcopy_bignum(t_bignum *res, t_bignum bn)
{
	int i;

	i = 0;
	res->maxsize = bn.maxsize;
	while (i < res->maxsize)
	{
		res->number[i] = bn.number[i];
		i++;
	}
	res->sign = bn.sign;
	res->size = bn.size;
	res->exp = bn.exp;

}
