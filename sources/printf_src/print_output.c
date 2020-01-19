/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:06:16 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 14:15:57 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_print_output.h>

#include <prf_out_fd.h>
#include <libft.h>

void		prepare_spec(t_specifications_def *spec)
{
	if (spec->flags & FLAG_PLUS)
		spec->flags &= (~FLAG_SPACE);
	if (spec->spec >= 5 && spec->spec <= 11 && spec->precision != NOT_DETERM)
		spec->flags &= (~FLAG_ZERO);
	if (spec->spec == 1)
		spec->flags &= (~FLAG_PLUS & ~FLAG_SPACE & ~FLAG_COMMA);
	if ((spec->spec == 12 || spec->spec == 14 || spec->spec == 15) &&
		spec->precision == NOT_DETERM)
		spec->precision = 6;
}

static int	is_zero(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (0);
	return (1);
}

static char	*determ_prefix(t_specifications_def spec, char *output)
{
	if (spec.spec != 3 && *output == '-')
	{
		ft_memmove(output, output + 1, ft_strlen(output));
		return ("-");
	}
	if (spec.flags & FLAG_PLUS)
		return ("+");
	if (spec.flags & FLAG_SPACE)
		return (" ");
	if (spec.flags & FLAG_OCTT && spec.spec == 7 && ((ft_strcmp(output, "0")
		&& spec.precision <= 0) || (output[0] != '0')))
		return ("0");
	if (*output == '\0')
		return (0);
	if (spec.flags & FLAG_OCTT && spec.spec == 9 && !is_zero(output))
		return ("0x");
	if (spec.flags & FLAG_OCTT && spec.spec == 10 && !is_zero(output))
		return ("0X");
	if (spec.flags & FLAG_OCTT && spec.spec == 11 && !is_zero(output))
		return ("0b");
	return (0);
}

int			print_output(t_specifications_def spec, char **output)
{
	char	*prefix;
	int		i;
	int		len;

	prefix = determ_prefix(spec, *output);
	len = ft_strlen(*output) + (prefix ? ft_strlen(prefix) : 0);
	if (spec.spec == 3 && **output == '\0')
		len++;
	if (prefix && (spec.flags & FLAG_ZERO))
		ft_buf_add(ft_get_g_outfd(), prefix, ft_strlen(prefix));
	if (spec.width > len && !((spec.flags & FLAG_MINUS) + (i = -1) * 0))
		while (++i < spec.width - len)
			ft_buf_add(ft_get_g_outfd(), spec.flags & FLAG_ZERO ? "0" : " ", 1);
	if (prefix && !(spec.flags & FLAG_ZERO))
		ft_buf_add(ft_get_g_outfd(), prefix, ft_strlen(prefix));
	if (spec.spec == 3 && **output == '\0')
		ft_buf_add(ft_get_g_outfd(), "", 1);
	ft_buf_add(ft_get_g_outfd(), *output, ft_strlen(*output));
	if (spec.width > len && spec.flags & FLAG_MINUS)
		while (++i < spec.width - len)
			ft_buf_add(ft_get_g_outfd(), " ", 1);
	return (spec.width > len ? spec.width : len);
}
