/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_handle_spec.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:04:53 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:40:28 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_HANDLE_SPEC_H
# define PRF_HANDLE_SPEC_H

# include <stdarg.h>

void			re_init_argmode(void);
const char		*is_valid_spec(const char *format);
int				handle_spec(const char **format, va_list argptr);

#endif
