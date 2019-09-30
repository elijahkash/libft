/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:29:33 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/30 12:35:06 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_SPEC_H
# define READ_SPEC_H

# include <ft_printf_spec.h>

int			read_flag(const char *format, t_specifications_def *spec);
const char	*read_width(const char *format, t_specifications_def *spec);
const char	*read_precision(const char *format, t_specifications_def *spec);
const char	*read_size(const char *format, t_specifications_def *spec,
						const char *sizes_map[NUMBER_OF_SIZES]);
const char	*read_specification(const char *format, t_specifications_def *spec,
						const t_specifications_def specs_def[NUMBER_OF_SPECS]);

const char	*read_spec(const char *format, t_specifications_def *spec,
						const t_specifications_def g_specs_def[NUMBER_OF_SPECS],
						const char *g_sizes_map[NUMBER_OF_SIZES]);

#endif
