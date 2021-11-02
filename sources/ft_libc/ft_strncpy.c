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

inline char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	return (strncpy(dst, src, len));
}

#else

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t tmp;

	tmp = (len > ft_strlen(src)) ? ft_strlen(src) : len;
	ft_bzero(dst, len);
	ft_memcpy(dst, src, tmp);
	return (dst);
}

#endif
