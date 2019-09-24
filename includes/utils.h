/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:50:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/24 16:06:01 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>

long long int			get_dec_item_by_size(va_list argptr, int size);

const char	*skip_digits(const char *format);
void		ft_getsnbr_base(long long int nbr, char *base, char *output);
void		ft_getnbr_base(unsigned long long int nbr, char *base,
															char *output);

#endif
