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

inline char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	return (strncat(s1, s2, n));
}

#else

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t tmp;
	size_t len;

	len = ft_strlen(s1);
	tmp = (n > ft_strlen(s2)) ? ft_strlen(s2) : n;
	ft_memcpy((void *)&(s1[len]), (void *)s2, tmp);
	s1[len + tmp] = '\0';
	return (s1);
}

#endif
