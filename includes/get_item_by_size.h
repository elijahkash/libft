/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item_by_size.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:50:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 23:26:27 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ITEM_BY_SIZE_H
# define GET_ITEM_BY_SIZE_H

# include <stdarg.h>

long long int			get_dec_item_by_size(va_list argptr, int size);
unsigned long long int	get_udec_item_by_size(va_list argptr, int size);
long double				get_float_item_by_size(va_list argptr, int size);

#endif
