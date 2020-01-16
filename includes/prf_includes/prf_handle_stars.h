/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_handle_stars.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:11:25 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:01 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_HANDLE_STARS_H
# define PRF_HANDLE_STARS_H

# include <prf_printf_spec.h>

# include <stdarg.h>

void	handle_stars(t_specifications_def *spec, va_list argptr,
													int g_arg_mode);

#endif
