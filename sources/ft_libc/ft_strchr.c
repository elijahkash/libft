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

inline char	*ft_strchr(const char *s, int c)
{
	return (strchr(s, c));
}

#else

char		*ft_strchr(const char *s, int c)
{
	const char *i;

	i = s;
	while (*i || c == '\0')
	{
		if (*i == (char)c)
			return ((char *)i);
		i++;
	}
	return (NULL);
}

#endif
