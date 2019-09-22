/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:29:33 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 14:01:07 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_SPEC_H
# define READ_SPEC_H

# include <ft_printf_spec.h>

const char			*read_spec(const char *format,
						t_specifications_def *spec,
						const t_specifications_def g_specs_def[NUMBER_OF_SPECS],
						const char *g_sizes_map[NUMBER_OF_SIZES]);

#endif
