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

#include "ft_diff_utils.h"

#include "ft_libc.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = ft_strlen(s);
	while (ft_isws(s[start]))
		start++;
	while (&s[end] != s && ft_isws(s[--end]))
		continue;
	len = (start < end) ? end - start + 1 : 0;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	ft_memcpy((void *)str, &(s[start]), len);
	return (str);
}
