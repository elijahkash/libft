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

#if defined USE_LIBC && ! defined __linux__

inline char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	return (strnstr(haystack, needle, len));
}

#else

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	if (needle[0] == 0 || len == 0)
		return ((needle[0] == 0) ? (char *)haystack : NULL);
	while (haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			check = 1;
			while (needle[++j] != 0 && i + j <= len)
			{
				check = (needle[j] == haystack[i + j]) ? 1 : 0;
				if (!check)
					break ;
			}
			if (check || i + j > len)
				return ((i + j > len) ? NULL : (char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}

#endif
