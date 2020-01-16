/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_outstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:08:25 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:02 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <libft.h>

char	*change_outstr(t_specifications_def spec, va_list argptr)
{
	if (spec.spec == 16)
	{
		ft_force_buff();
		ft_set_g_outstr(va_arg(argptr, char*));
	}
	return (ft_zerostr());
}
