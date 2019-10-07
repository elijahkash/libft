/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:51:11 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 13:03:54 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HOLD_OVER_FORCE 2
# define IMMIDIATLY_FORCE 1

# define FORCE_BUFF_POLICY HOLD_OVER_FORCE

int				ft_printf(const char *format, ...);

#endif
