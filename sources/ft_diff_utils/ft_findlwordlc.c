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

size_t	ft_findlwordlc(char const *s, char c)
{
	size_t	curlen;
	size_t	maxlen;
	int		is_word;

	if (!s)
		return (0);
	is_word = 0;
	curlen = 0;
	maxlen = 0;
	while (*s)
	{
		curlen = (*s != c) ? curlen + 1 : curlen;
		if (is_word && *s == c)
		{
			maxlen = (curlen > maxlen) ? curlen : maxlen;
			is_word = 0;
			curlen = 0;
		}
		if (*s != c && !is_word)
			is_word++;
		s++;
	}
	if (is_word)
		maxlen = (curlen > maxlen) ? curlen : maxlen;
	return (maxlen);
}
