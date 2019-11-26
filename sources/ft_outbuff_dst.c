/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_dst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:42:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:47:54 by mtrisha          ###   ########.fr       */
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
