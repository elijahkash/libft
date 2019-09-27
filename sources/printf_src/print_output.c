/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:06:16 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 19:48:57 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <print_output.h>

#include <libft.h>

void		prepare_spec(t_specifications_def *spec)
{
	if (spec->flags & FLAG_PLUS)
		spec->flags &= (~FLAG_SPACE);
	if (spec->spec >= 5 && spec->spec <= 11 && spec->precision != NOT_DETERM)
		spec->flags &= (~FLAG_ZERO);
	if (spec->spec == 1)
		spec->flags &= (~FLAG_PLUS & ~FLAG_SPACE & ~FLAG_COMMA);
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
	if (spec.flags & FLAG_OCTT && spec.spec == 7 && ft_strcmp(output, "0"))
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

void		handle_comma_flag(char **output)
{
	if (*output)
		return ;
	return ;
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
		ft_putstr_fd(prefix, g_fd_printf);
	if (spec.width > len && !((spec.flags & FLAG_MINUS) + (i = -1) * 0))
		while (++i < spec.width - len)
			ft_putchar_fd(spec.flags & FLAG_ZERO ? '0' : ' ', g_fd_printf);
	if (prefix && !(spec.flags & FLAG_ZERO))
		ft_putstr_fd(prefix, g_fd_printf);
	if (spec.spec == 3 && **output == '\0')
		ft_putchar_fd('\0', g_fd_printf);
	ft_putstr_fd(*output, g_fd_printf);
	if (spec.width > len && spec.flags & FLAG_MINUS)
		while (++i < spec.width - len)
			ft_putchar_fd(' ', g_fd_printf);
	return (spec.width > len ? spec.width : len);
}
