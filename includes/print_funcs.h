/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:42:40 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/20 22:16:49 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNC_H
# define PRINT_FUNC_H

# include <ft_printf_spec.h>

# include <stdarg.h>

int		print_percent(t_specifications_def spec, va_list argptr);

#endif
