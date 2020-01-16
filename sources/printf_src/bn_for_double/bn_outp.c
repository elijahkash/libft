/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_outp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:31:16 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:44 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

#include <libft.h>

static void		reformat_checkzero(char *output, int prec, char *c)
{
	while (prec-- >= 0 && *c != '\0')
		c++;
	if (*c != '\0')
		*c = '\0';
	else
	{
		prec++;
		while (prec-- >= 0)
			ft_strcat(output, "0");
	}
}

void			reformat_output(char *output, t_specifications_def spec)
{
	char *c;

	c = ft_strchr(output, '.');
	if (spec.precision == 0)
	{
		if (spec.flags & FLAG_OCTT)
		{
			if (c != NULL)
				*(++c) = '\0';
			else
				ft_strcat(output, ".");
		}
		else if (c != NULL)
			*c = '\0';
		return ;
	}
	if (c != NULL)
		reformat_checkzero(output, spec.precision, c);
	else
	{
		ft_strcat(output, ".");
		putnzeros(output, spec.precision);
	}
}

static void		put_bn_outp_aux(t_bignum res, char *output, int *i)
{
	if (res.size - 1 <= (res.exp - 1) / 4)
	{
		*i = (res.exp - 1) / 4;
		ft_strcatnbr(output, res.number[(res.exp - 1) / 4] /
				ft_pow_bn(10, (res.exp - 1) % 4 + 1));
	}
	else
	{
		ft_strcatnbr(output, res.number[res.size - 1]);
		*i = res.size - 2;
		while (*i > (res.exp - 1) / 4)
		{
			ft_strcatnbr_wzeros(output, res.number[*i], 4);
			(*i)--;
		}
		if (3 - (res.exp - 1) % 4 > 0)
			ft_strcatnbr_wzeros(output,
						res.number[*i] / ft_pow_bn(10, (res.exp - 1) % 4 + 1),
						3 - (res.exp - 1) % 4);
	}
}

void			put_bn_output(t_bignum res, char *output,
							t_specifications_def spec)
{
	int i;

	if (res.sign == -1)
		ft_strcat(output, "-");
	if (res.size == 0)
	{
		ft_strcat(output, "0");
		return ;
	}
	put_bn_outp_aux(res, output, &i);
	ft_strcat(output, ".");
	ft_strcatnbr_wzeros(output,
		res.number[(res.exp - 1) / 4] % ft_pow_bn(10, (res.exp - 1) % 4 + 1),
		(res.exp - 1) % 4 + 1);
	i--;
	while (i >= 0)
		ft_strcatnbr_wzeros(output, res.number[i--], 4);
	reformat_output(output, spec);
}
