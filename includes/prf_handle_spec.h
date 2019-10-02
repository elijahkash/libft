/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_handle_spec.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:04:53 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 21:23:09 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_HANDLE_SPEC_H
# define PRF_HANDLE_SPEC_H

# include <stdarg.h>

void			re_init_argmode(void);
const char		*is_valid_spec(const char *format);
int				handle_spec(const char **format, va_list argptr);

#endif
