/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_comma_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:06:17 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:07 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_handle_comma_flag.h>

#include <libft.h>

static void	handle_comma_intpart(char *output, int pos)
{
	int i;

	while (pos > 0)
	{
		i = 0;
		while (i < 2 && pos > 0)
		{
			i++;
			pos--;
		}
		if (pos != 0 && output[pos - 1] != '-')
		{
			ft_memmove(&(output[pos + 1]), &(output[pos]),
							1 + ft_strlen(&(output[pos])));
			output[pos] = LC_NUMERIC_ASCII;
			pos--;
		}
	}
}

static void	handle_comma_fractpart(char *output, int pos)
{
	int i;

	while (ft_isdigit(output[pos]))
	{
		i = 0;
		while (i < 3 && ft_isdigit(output[pos]))
		{
			i++;
			pos++;
		}
		if (ft_isdigit(output[pos]))
		{
			ft_memmove(&(output[pos + 1]), &(output[pos]),
							1 + ft_strlen(&(output[pos])));
			output[pos] = LC_NUMERIC_ASCII;
			pos++;
		}
	}
}

void		handle_comma_flag(char *output)
{
	char *dot;

	dot = ft_strchr(output, '.');
	if (dot == NULL)
		handle_comma_intpart(output, ft_strlen(output) - 1);
	else
	{
		handle_comma_fractpart(output, dot - output + 1);
		handle_comma_intpart(output, dot - output - 1);
	}
}
