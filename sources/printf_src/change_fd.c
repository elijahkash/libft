/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:43:08 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 12:10:28 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

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
