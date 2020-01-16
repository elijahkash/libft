/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_double.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:02:32 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:55:26 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_DOUBLE_H
# define PRF_DOUBLE_H

# include <prf_printf_spec.h>

# include <stdarg.h>

# define SIZE_BN 5000
# define BASE_BN 10000

union						u_double
{
	long double				ld;
	struct
	{
		unsigned long int	m : 64;
		unsigned int		e : 15;
		unsigned int		s : 1;
	}						s_parts;
};

typedef struct				s_bignum
{
	long long int			number[SIZE_BN];
	int						sign;
	int						size;
	int						exp;
	int						normalexp;
	int						maxsize;
}							t_bignum;

typedef struct				s_bigdec
{
	t_bignum				intpart;
	t_bignum				fractpart;
	int						sizefract;
	int						prec;
	int						sign;
}							t_bigdec;

void						initialize_bignum(t_bignum *n, int maxsize);
void						initialize_bd(t_bigdec *bd, int maxsize);
void						ft_assign_bignum(t_bignum *bn, int maxsize,
											long long n);
void						fixzero_bignum(t_bignum *bn);
void						fixsize_bignum(t_bignum *bn);
void						fixup_bignum(t_bignum *bn);
void						ft_isumabs_bignum(t_bignum *res, t_bignum bn2);
void						ft_imul_bignum(t_bignum *res, t_bignum bn2);
void						ft_deepcopy_bignum(t_bignum *res, t_bignum bn);
void						ft_ipow_bignum(t_bignum *res, unsigned int n);
t_bignum					ft_mul_bignum(t_bignum bn1, t_bignum bn2);
t_bignum					ft_pow_bignum(t_bignum bn, unsigned int n);
void						putnzeros(char *output, int prec);
void						ft_itoa_f(union u_double d, char *output,
										t_specifications_def spec);
int							ft_pow_bn(int num, unsigned int p);
void						ft_strcatnbr(char *output, long int nbr);
void						ft_putnbr_output(long int n, char *output);
void						ft_put_one_inpos_bignum(t_bignum *bn,
													int maxsize, int pos);
void						prf_dblcalc(long double d, char *str,
										t_specifications_def spec);
int							ft_get_inpos_bignum(t_bignum bn, int pos);
void						put_bn_output(t_bignum res, char *output,
										t_specifications_def spec);
void						reformat_output(char *output,
										t_specifications_def spec);
void						round_bn(t_bignum *res, int prec);
void						ft_strcatnbr_wzeros(char *output, long long nbr,
												int len);
void						makebnwithfract(t_bignum *res, t_bigdec bd);
int							countmaxsize_bignum(int exp);
void						fixdown_bignum(t_bignum *bn);
t_bignum					ft_div_bignum(t_bignum a, t_bignum b);
void						ft_ipow_small_bignum(t_bignum *res,
									unsigned int n, unsigned int pow);
void						ft_imul_small_bignum(t_bignum *res, unsigned int n);
void						normalize_bn(t_bignum *res);
int							ft_nbrlen(long int a);
void						ft_intpart(int pow, unsigned long int mant,
										int exp, t_bigdec *bd);
void						ft_fractpart(int pow, unsigned long int mant,
										t_bigdec *bd);
int							is_last_five(t_bignum res, int start_check);

#endif
