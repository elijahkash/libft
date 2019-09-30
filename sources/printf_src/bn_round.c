#include "double.h"

void			ft_put_one_inpos_bignum(t_bignum *bn, int maxsize, int pos)
{
	initialize_bignum(bn, maxsize);
	bn->number[(pos - 1) / 4] = ft_pow_bn(10, (pos - 1) % 4);
	bn->size = (pos - 1) / 4 + 1;
	bn->sign = 1;
}

int 			ft_get_inpos_bignum(t_bignum bn, int pos)
{
	int tmp;

	if (pos <= 0)
		return (0);
	tmp = bn.number[(pos - 1) / 4] / ft_pow_bn(10, (pos - 1) % 4);
	return (tmp % 10);
}

static void 	zeroafterround(t_bignum *res, int pos)
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

void 			round_bn(t_bignum *res, int prec)
{
	t_bignum ten;

	//TODO сделать обработчик для prec < 0 - то есть округление целочисленной части
	if (res->exp - prec < 0)
		return ; //(значит, мы вышли за пределы массива чисел, не нужно делать округление)
	else
	{
		if (ft_get_inpos_bignum(*res, res->exp - prec) >= 5)
		{
			ft_put_one_inpos_bignum(&ten, res->maxsize, res->exp - prec + 1);
			ft_isumabs_bignum(res, ten);
		}
		zeroafterround(res, res->exp - prec);
	}
}