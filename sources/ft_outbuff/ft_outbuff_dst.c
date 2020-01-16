/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_dst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:42:42 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:26 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff_dst.h>

#include <libft.h>

static char		*g_outstr = NULL;
static int		g_outfd = FD_STDOUT;

inline void		ft_set_g_outstr(char *ptr)
{
	g_outstr = ptr;
}

inline void		ft_set_g_outfd(int value)
{
	g_outfd = value;
}

inline int		ft_get_g_outfd(void)
{
	return (g_outfd);
}

inline char		*ft_get_g_outstr(void)
{
	return (g_outstr);
}
