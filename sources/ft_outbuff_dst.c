/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_dst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:42:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 18:06:19 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff_dst.h>

#include <libft.h>

static char		*g_outstr = NULL;
static int		g_outfd = 1;

void			ft_set_g_outstr(char *ptr)
{
	g_outstr = ptr;
}

void			ft_set_g_outfd(int value)
{
	g_outfd = value;
}

int				ft_get_g_outfd(void)
{
	return (g_outfd);
}

char			*ft_get_g_outstr(void)
{
	return (g_outstr);
}
