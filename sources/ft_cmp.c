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

#include "ft_cmp.h"

#include "ft_libc.h"
#include <string.h>

inline int		ft_icmp(const void *p1, const void *p2)
{
	return (*((int *)p1) - *((int *)p2));
}

inline int		ft_ccmp(const void *p1, const void *p2)
{
	return (*((char *)p1) - *((char *)p2));
}

inline int		ft_scmp(const void *p1, const void *p2)
{
	return (ft_strcmp(*((char **)p1), *((char **)p2)));
}

inline int		ft_zcmp(const void *p1, const void *p2)
{
	return (*((size_t *)p1) - *((size_t *)p2));
}

inline int		ft_pcmp(const void *p1, const void *p2)
{
	return (*(void **)p1 - *(void **)p2);
}
