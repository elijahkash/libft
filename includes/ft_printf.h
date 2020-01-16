/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:51:11 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:23 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HOLD_OVER_FORCE 0
# define IMMIDIATLY_FORCE 1

# define FORCE_BUFF_POLICY HOLD_OVER_FORCE

int				ft_printf(const char *format, ...);

#endif
