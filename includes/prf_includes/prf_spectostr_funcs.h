/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_spectostr_funcs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:42:40 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:55 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_SPECTOSTR_FUNCS_H
# define PRF_SPECTOSTR_FUNCS_H

# include <prf_printf_spec.h>
# include <stdarg.h>

char	*spectostr_percent(t_specifications_def spec, va_list argptr);
char	*spectostr_string(t_specifications_def spec, va_list argptr);
char	*spectostr_char(t_specifications_def spec, va_list argptr);
char	*spectostr_ptr(t_specifications_def spec, va_list argptr);
char	*spectostr_sdec(t_specifications_def spec, va_list argptr);
char	*spectostr_sdec(t_specifications_def spec, va_list argptr);
char	*spectostr_oct(t_specifications_def spec, va_list argptr);
char	*spectostr_udec(t_specifications_def spec, va_list argptr);
char	*spectostr_lowhex(t_specifications_def spec, va_list argptr);
char	*spectostr_bighex(t_specifications_def spec, va_list argptr);
char	*spectostr_float(t_specifications_def spec, va_list argptr);
char	*spectostr_bin(t_specifications_def spec, va_list argptr);
char	*change_fd(t_specifications_def spec, va_list argptr);
char	*change_outstr(t_specifications_def spec, va_list argptr);

#endif
