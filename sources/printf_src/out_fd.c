/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:13:25 by Kashnitskiy       #+#    #+#             */
/*   Updated: 2020/01/19 14:25:54 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_out_fd.h>

#include <libft.h>

static int		g_outfd = FD_STDOUT;

inline void		ft_set_g_outfd(int value)
{
	g_outfd = value;
}

inline int		ft_get_g_outfd(void)
{
	return (g_outfd);
}
