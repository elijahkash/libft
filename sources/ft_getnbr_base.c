/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:16:44 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/25 13:19:26 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int						check_base(char *base)
{
	int i;
	int j;
	int len;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i;
		while (++j < len)
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

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

	if (!check_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
		*output++ = '-';
	bit_counter_in_base = get_bit_counter_in_base(nbr, base_len);
	while (bit_counter_in_base)
	{
		*output++ = base[ABS(nbr / bit_counter_in_base)];
		nbr = ABS(nbr % bit_counter_in_base);
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
