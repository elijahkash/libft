/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:54:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/02 17:22:11 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

void	prf_dblcalc(long double d, char *str, t_specifications_def spec)
{
	union u_double ud;

	ud.ld = d;
	ft_itoa_f(ud, str, spec);
}
