/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:43:08 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 14:16:09 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <prf_out_fd.h>
#include <libft.h>

char	*change_fd(t_specifications_def spec, va_list argptr)
{
	if (spec.spec == 13)
	{
		if (ft_get_g_outstr())
		{
			ft_force_buff();
			ft_set_g_outstr(NULL);
		}
		ft_set_g_outfd(va_arg(argptr, int));
	}
	return (ft_zerostr());
}
