/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:41:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/24 18:20:56 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#include <libft.h>

void					strset(char *str, char c, int len)
{
	while (len--)
		*str++ = c;
}

long long int			get_dec_item_by_size(va_list argptr, int size)
{
	if (size == 1)
		return (va_arg(argptr, long long int));
	if (size == 2)
		return ((char)va_arg(argptr, int));
	if (size == 4)
		return (va_arg(argptr, long int));
	if (size == 8)
		return ((short int)va_arg(argptr, int));
	return (va_arg(argptr, int));
}

const char	*skip_digits(const char *format)
{
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static int				check_base(char *base)
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

static long long int	get_bit_counter_in_base(long long int nbr, int base)
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

void					ft_getsnbr_base(long long int nbr, char *base,
															char *output)
{
	int				base_len;
	long long int	bit_counter_in_base;
	long long int	src_nbr;

	src_nbr = nbr;
	if (!check_base(base))
		return ;
	if (!nbr) //TODO: you really need it? or ZERO can be nandle by main rule?
	{
		output[0] = base[0];
		output[1] = '\0';
		return ;
	}
	base_len = ft_strlen(base);
	if (nbr < 0) //TODO: need handle min value
	{
		*output++ = '-';
		src_nbr *= -1;
	}
	bit_counter_in_base = get_bit_counter_in_base(src_nbr, base_len);
	while (bit_counter_in_base)
	{
		*output++ = base[src_nbr / bit_counter_in_base];
		src_nbr %= bit_counter_in_base;
		bit_counter_in_base /= base_len;
	}
	*output = '\0';
}

void					ft_getnbr_base(unsigned long long int nbr, char *base,
															char *output)
{
	int				base_len;
	long long int	bit_counter_in_base;
	long long int	src_nbr;

	src_nbr = nbr;
	if (!check_base(base))
		return ;
	if (!nbr) //TODO: you really need it? or ZERO can be nandle by main rule?
	{
		output[0] = base[0];
		output[1] = '\0';
		return ;
	}
	base_len = ft_strlen(base);
	bit_counter_in_base = get_bit_counter_in_base(src_nbr, base_len);
	while (bit_counter_in_base)
	{
		*output++ = base[src_nbr / bit_counter_in_base];
		src_nbr %= bit_counter_in_base;
		bit_counter_in_base /= base_len;
	}
	*output = '\0';
}
