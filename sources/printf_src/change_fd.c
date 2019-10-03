/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:43:08 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 15:16:37 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <libft.h>

char	*change_fd(t_specifications_def spec, va_list argptr)
{
	if (spec.spec == 13)
		ft_set_g_outfd(va_arg(argptr, int));
	return (ft_zerostr());
}
