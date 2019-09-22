/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:06:16 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 17:42:10 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

#include <libft.h>

void		prepare_spec(t_specifications_def *spec)
{
	if (spec->flags & FLAG_PLUS)
		spec->flags &= (~FLAG_SPACE);
	if (spec->spec >= 6 && spec->spec <= 11 && spec->precision)
		spec->flags &= (~FLAG_ZERO);
	if (spec->spec == 1)
		spec->flags &= (~FLAG_PLUS & ~FLAG_SPACE & ~FLAG_COMMA);
}

static char	determ_prefix(t_specifications_def spec, char *output)
{
	if (*output == '-')
		return (0);
	if (spec.flags & FLAG_PLUS)
		return ('+');
	if (spec.flags & FLAG_SPACE)
		return (' ');
	return (0);
}

static void	handle_comma_flag(char **output)
{
	//TODO: реализуй это
	if (*output)
		return ;
	return ;
}

int			print_output(t_specifications_def spec, char **output)
{
	char	prefix;
	int		i;
	int		len;

	i = -1;
	prefix = determ_prefix(spec, *output);
	if (spec.flags & FLAG_COMMA)
		handle_comma_flag(output);
	if (!*output)
		return (-1);
	len = ft_strlen(*output) + (prefix ? 1 : 0);
	if (spec.width > len && !(spec.flags & FLAG_MINUS))
		while (++i < spec.width - len)
			ft_putchar(spec.flags & FLAG_ZERO ? '0' : ' ');
	if (prefix)
		ft_putchar(prefix);
	ft_putstr(*output);
	if (spec.width > len && spec.flags & FLAG_MINUS)
		while (++i < spec.width - len)
			ft_putchar(' ');
	return (spec.width > len ? spec.width : len);
}
