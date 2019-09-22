/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_funcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:42:40 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 17:07:26 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECTOSTR_FUNCS_H
# define SPECTOSTR_FUNCS_H

# include <ft_printf_spec.h>

# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>

char	*spectostr_percent(t_specifications_def spec, va_list argptr);

#endif
