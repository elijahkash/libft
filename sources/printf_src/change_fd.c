/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:43:08 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/27 19:50:27 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

char	*change_fd(t_specifications_def spec, va_list argptr)
{
	if (spec.spec == 13)
		g_fd_printf = va_arg(argptr, int);
	return (ft_zerostr());
}
