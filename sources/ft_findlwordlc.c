/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findlwordlc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:29:37 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/21 12:12:42 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

size_t	ft_findlwordlf(t_str s, int (*f)(char))
{
	size_t	curlen;
	size_t	maxlen;
	size_t	i;
	int		is_word;

	if (!(s.str + (i = 0) * 0))
		return (0);
	is_word = 0;
	curlen = 0;
	maxlen = 0;
	while (i < s.len)
	{
		curlen = (!f(s.str[i])) ? curlen + 1 : curlen;
		if (is_word && f(s.str[i]))
		{
			maxlen = (curlen > maxlen) ? curlen : maxlen;
			is_word = 0;
			curlen = 0;
		}
		(!f(s.str[i]) && !is_word) ? is_word++ : 0;
		i++;
	}
	if (is_word)
		maxlen = (curlen > maxlen) ? curlen : maxlen;
	return (maxlen);
}
