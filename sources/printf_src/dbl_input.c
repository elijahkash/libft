#include "double.h"

void	prf_dblcalc(long double d, int prec, char *str)
{
	union u_double ud;

	ud.ld = d;
	ft_itoa_f(ud, str, prec);
}
