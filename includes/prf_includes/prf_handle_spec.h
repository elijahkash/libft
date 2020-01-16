/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_handle_spec.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:04:53 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:03 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_HANDLE_SPEC_H
# define PRF_HANDLE_SPEC_H

# include <stdarg.h>

void			re_init_argmode(void);
const char		*is_valid_spec(const char *format);
int				handle_spec(const char **format, va_list argptr);

#endif
