/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:16:44 by mtrisha           #+#    #+#             */
/*   Updated: 2020/03/01 14:05:07 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

static long long int			get_bit_counter_in_base(
								long long int nbr, int base)
{
	long long int result;

	result = 1;
	while (nbr / base != 0)
	{
		result *= base;
		nbr /= base;
	}
	return (result);
}

static unsigned long long int	get_ubit_counter_in_base(
								unsigned long long int nbr,
								int base)
{
	unsigned long long int result;

	result = 1;
	while (nbr / base != 0)
	{
		result *= base;
		nbr /= base;
	}
	return (result);
}

void							ft_getsnbr_base(long long int nbr,
												char *base, char *output)
{
	int				base_len;
	long long int	bit_counter_in_base;
	long long int	tmp;

	if (!check_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
		*output++ = '-';
	bit_counter_in_base = get_bit_counter_in_base(nbr, base_len);
	while (bit_counter_in_base)
	{
		tmp = nbr / bit_counter_in_base;
		*output++ = base[tmp >= 0 ? tmp : tmp * -1];
		tmp = nbr % bit_counter_in_base;
		nbr = tmp >= 0 ? tmp : tmp * -1;
		bit_counter_in_base /= base_len;
	}
	*output = '\0';
}

void							ft_getunbr_base(unsigned long long int nbr,
												char *base, char *output)
{
	int						base_len;
	unsigned long long int	bit_counter_in_base;

	if (!check_base(base))
		return ;
	base_len = ft_strlen(base);
	bit_counter_in_base = get_ubit_counter_in_base(nbr, base_len);
	while (bit_counter_in_base)
	{
		*output++ = base[nbr / bit_counter_in_base];
		nbr %= bit_counter_in_base;
		bit_counter_in_base /= base_len;
	}
	*output = '\0';
}

void							ft_getunbr_goodbase(unsigned long long int nbr,
								char *base, __uint32_t baselen, char *output)
{
	unsigned long long int	bit_counter_in_base;

	bit_counter_in_base = get_ubit_counter_in_base(nbr, baselen);
	while (bit_counter_in_base)
	{
		*output++ = base[nbr / bit_counter_in_base];
		nbr %= bit_counter_in_base;
		bit_counter_in_base /= baselen;
	}
	*output = '\0';
}
