/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:53:01 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 22:06:03 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <read_spec.h>

#include <libft.h>
#include <extend_dollar.h>

static int			read_flag(const char *format, t_specifications_def *spec)
{
	char *ptr;

	if ((ptr = ft_strchr(FLAGS, *format)))
	{
		spec->flags |= ft_pow(2, (ptr - FLAGS));
		return (1);
	}
	return (0);
}

static const char	*read_width(const char *format,
									t_specifications_def *spec)
{
	if (*format == '*')
	{
		if (is_dollor(format) && (spec->width = ft_atoi(format) * -1))
			format = skip_dollor(format);
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

static const char	*read_precision(const char *format,
									t_specifications_def *spec)
{
	if (*format == '.')
	{
		if (*(++format) == '*')
		{
			if (is_dollor(format + 1) &&
				(spec->precision = ft_atoi(format + 1) * -1))
				format = skip_dollor(++format);
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

static const char	*read_size(const char *format, t_specifications_def *spec,
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

static const char	*read_specification(const char *format,
								t_specifications_def *spec,
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

const char			*read_spec(const char *format,
						t_specifications_def *spec,
						const t_specifications_def g_specs_def[NUMBER_OF_SPECS],
						const char *g_sizes_map[NUMBER_OF_SIZES])
{
	if (is_dollor(format) && (spec->arg = ft_atoi(format)))
		format = skip_dollor(format);
	else
		spec->arg = -1;
	while (read_flag(format, spec))
		format++;
	format = read_width(format, spec);
	format = read_precision(format, spec);
	format = read_size(format, spec, g_sizes_map);
	format = read_specification(format, spec, g_specs_def);
	return (format);
}
