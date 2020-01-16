/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:53:01 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:10 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_read_spec.h>

#include <libft.h>
#include <prf_extend_dollar.h>

int			read_flag(const char *format, t_specifications_def *spec)
{
	char *ptr;

	if ((ptr = ft_strchr(FLAGS, *format)))
	{
		spec->flags |= ft_pow(2, (ptr - FLAGS));
		return (1);
	}
	return (0);
}

const char	*read_width(const char *format, t_specifications_def *spec)
{
	if (*format == '*')
	{
		if (is_dollar(format + 1) && (spec->width = ft_atoi(format++ + 1) * -1))
			format = skip_dollar(format);
		else
			spec->width = READ_DATA + *(format++) * 0;
	}
	else if (ft_isdigit(*format))
	{
		spec->width = ft_atoi(format);
		format = ft_skip_digits(format);
	}
	else
		spec->width = NOT_DETERM;
	return (format);
}

const char	*read_precision(const char *format, t_specifications_def *spec)
{
	if (*format == '.')
	{
		if (*(++format) == '*')
		{
			if (is_dollar(format + 1) &&
				(spec->precision = ft_atoi(format + 1) * -1))
				format = skip_dollar(++format);
			else
				spec->precision = READ_DATA + *(format++) * 0;
		}
		else if (!ft_isdigit(*format))
			spec->precision = 0;
		else
		{
			spec->precision = ft_atoi(format);
			format = ft_skip_digits(format);
		}
	}
	else
		spec->precision = NOT_DETERM;
	return (format);
}

const char	*read_size(const char *format, t_specifications_def *spec,
						const char *sizes_map[NUMBER_OF_SIZES])
{
	int		i;
	char	*ptr;

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

const char	*read_specification(const char *format, t_specifications_def *spec,
						const t_specifications_def specs_def[NUMBER_OF_SPECS])
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
