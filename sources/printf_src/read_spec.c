/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:53:01 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/01 23:02:10 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <read_spec.h>

#include <libft.h>
#include <extend_dollar.h>

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
