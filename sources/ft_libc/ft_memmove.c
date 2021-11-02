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

#include "ft_libc.h"

#ifdef USE_LIBC

inline void	*ft_memmove(void *dst, const void *src, size_t len)
{
	return (memmove(dst, src, len));
}

#else

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (dst == src && dst == NULL)
		return (NULL);
	if (dst >= src)
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

#endif
