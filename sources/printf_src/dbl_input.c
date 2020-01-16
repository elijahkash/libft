/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:54:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:58:03 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

void	prf_dblcalc(long double d, char *str, t_specifications_def spec)
{
	union u_double ud;

	ud.ld = d;
	ft_itoa_f(ud, str, spec);
}
