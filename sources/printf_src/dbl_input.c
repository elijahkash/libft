/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:54:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/02 00:07:45 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void	prf_dblcalc(long double d, int prec, char *str, char spec)
{
	union u_double ud;

	ud.ld = d;
	ft_itoa_f(ud, str, prec, spec);
}
