/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_handle_stars.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:11:25 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 17:09:57 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_STARS_H
# define HANDLE_STARS_H

# include <prf_printf_spec.h>

# include <stdarg.h>

void	handle_stars(t_specifications_def *spec, va_list argptr,
													int g_arg_mode);

#endif
