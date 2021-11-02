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

inline char	*ft_strrchr(const char *s, int c)
{
	return (strrchr(s, c));
}

#else

char		*ft_strrchr(const char *s, int c)
{
	const char *i;

	i = &s[ft_strlen(s)];
	while (i >= s)
	{
		if (*i == (char)c)
			return ((char *)i);
		i--;
	}
	return (NULL);
}

#endif
