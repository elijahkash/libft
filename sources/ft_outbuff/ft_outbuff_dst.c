/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_dst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:42:42 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 14:13:45 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_outbuff_dst.h"

#include "libft.h"

static char		*g_outstr = NULL;

inline void		ft_set_g_outstr(char *ptr)
{
	g_outstr = ptr;
}

inline char		*ft_get_g_outstr(void)
{
	return (g_outstr);
}
