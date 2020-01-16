/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:08:47 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:01 by Kashnitskiy      ###   ########.fr       */
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
