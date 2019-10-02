/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_spectostr_funcs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:42:40 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 21:22:48 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_SPECTOSTR_FUNCS_H
# define PRF_SPECTOSTR_FUNCS_H

# include <prf_printf_spec.h>
# include <stdarg.h>
# include <stdlib.h>
# include <prf_get_item_by_size.h>
# include <libft.h>

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
