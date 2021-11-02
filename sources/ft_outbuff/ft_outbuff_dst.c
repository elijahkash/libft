/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
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
