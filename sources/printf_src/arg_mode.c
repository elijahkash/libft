/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:08:47 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 20:13:29 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_arg_mode.h>

/*
** if dollar mode g_arg_mode > 0 else < 0
*/
static int	g_arg_mode = 0;

void		init_argmode(void)
{
	g_arg_mode = 0;
}

int			get_argmode(void)
{
	return (g_arg_mode);
}

void		set_argmode(int value)
{
	g_arg_mode = value;
}
