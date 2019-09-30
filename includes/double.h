#ifndef DOUBLE_H
#define DOUBLE_H

# include <stdarg.h>

# define SIZE_BN 1300
# define BASE_BN 10000

union 						u_double
{
	long double				ld;
	struct
	{
		unsigned long int	m : 64;
		unsigned int		e : 15;
		unsigned int		s : 1;
	}						s_parts;
};

typedef struct		s_bignum
{
	long long int	number[SIZE_BN];
	int 			sign;
	int 			size;
	int				exp;
	int 			maxsize;
}					t_bignum;

typedef struct 		s_bigdec
{
	t_bignum		intpart;
	t_bignum		fractpart;
	int				sizefract;
	int 			prec;
	int 			sign;
}					t_bigdec;

void			initialize_bignum(t_bignum *n, int maxsize);
void			initialize_bd(t_bigdec *bd, int maxsize);
void			ft_assign_bignum(t_bignum *bn, int maxsize, long long n);
void			fixzero_bignum(t_bignum *bn);
void			fixsize_bignum(t_bignum *bn);
void			fixup_bignum(t_bignum *bn);
void			ft_isumabs_bignum(t_bignum *res, t_bignum bn2);
void			ft_imul_bignum(t_bignum *res, t_bignum bn2);
void			ft_deepcopy_bignum(t_bignum *res, t_bignum bn);
void			ft_ipow_bignum(t_bignum *res, unsigned int n);
t_bignum		ft_mul_bignum(t_bignum bn1, t_bignum bn2);
t_bignum		ft_pow_bignum(t_bignum bn, unsigned int n);
void			putnzeros(char *output, int prec);
int 			ft_itoa_f(union u_double d, char *output, int prec);
int				ft_pow_bn(int num, unsigned int p);
void			initialize_bd(t_bigdec *bd, int maxsize);
void			ft_strcatnbr(char *output, long int nbr);
void			ft_putnbr_output(long int n, char *output);
void			ft_put_one_inpos_bignum(t_bignum *bn, int maxsize, int pos);
void			prf_dblcalc(long double d, int prec, char *str);
int 			ft_get_inpos_bignum(t_bignum bn, int pos);
void 			put_bn_output(t_bignum res, char *output, int prec);
void			reformat_output(char *output, int prec);
void 			round_bn(t_bignum *res, int prec);
void			ft_strcatnbr_wzeros(char *output, long long nbr, int len);

#endif
