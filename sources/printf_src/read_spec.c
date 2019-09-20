/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:53:01 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/20 16:46:08 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_spec.h>

#include <libft.h>

static int get_flag_bit(const char c)
{
	if (c == '-')
		return (FLAG_MINUS);
	if (c == '+')
		return (FLAG_PLUS);
	if (c == '0')
		return (FLAG_ZERO);
	if (c == ' ')
		return (FLAG_SPACE);
	if (c == '\'')
		return (FLAG_COMMA);
	return (0);
}

static int			read_flag(const char *format, t_specifications_def *spec)
{
	if (ft_strchr(FLAGS, *format))
	{
		spec->flags |= get_flag_bit(*format);
		return (1);
	}
	return (0);
}

static const char	*read_size(const char *format, t_specifications_def *spec)
{
	int		i;
	char 	*ptr;

	i = -1;
	while (++i < NUMBER_OF_SIZES)
		if ((ptr = ft_strnstr(format, sizes_map[i], SIZE_MAX_LEN + 1)))
		{
			if (ptr != format)
				continue ;
			spec->sizes = ft_pow(2, i);
			format += ft_strlen(sizes_map[i]);
			break ;
		}
	return (format);
}

static const char	*read_specification(const char *format,
										t_specifications_def *spec)
{
	int		i;

	i = -1;
	while (++i < NUMBER_OF_SPECS)
		if (*format == specs_def[i].spec)
		{
			spec->spec = i + 1;
			break ;
		}
	return (++format);
}

const char			*read_spec(const char *format, t_specifications_def *spec)
{
	while (read_flag(format, spec))
		format++;
	if (ft_isdigit(*format))
	{
		spec->width = ft_atoi(format);
		format = skip_digits(format);
	}
	if (*format == '.')
	{
		spec->precision = ft_atoi(++format);
		format = skip_digits(format);
	}
	format = read_size(format, spec);
	format = read_specification(format, spec);
	return (format);
}
