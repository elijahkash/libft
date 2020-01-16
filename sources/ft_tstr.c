/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:35:36 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:19 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tstr.h>

#include <libft.h>

t_str	*ft_tstrdup(t_str s)
{
	t_str	*res;

	res = ft_malloc(sizeof(t_str));
	res->str = ft_strnew(s.len + 1);
	res->len = s.len;
	ft_memcpy(res->str, s.str, s.len);
	return (res);
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

size_t	ft_cfwords(t_str s, int (*f)(char))
{
	size_t	count;
	int		is_word;
	size_t	i;

	i = 0;
	if (!s.str)
		return (0);
	is_word = 0;
	count = 0;
	while (i < s.len)
	{
		if (is_word && f(s.str[i]))
		{
			count++;
			is_word = 0;
		}
		if (!f(s.str[i]) && !is_word)
			is_word++;
		i++;
	}
	if (is_word)
		count++;
	return (count);
}

t_str	**ft_tstrsplit(t_str s, int (*f)(char))
{
	char	temp_str[ft_findlwordlf(s, f) + 1];
	t_str	temp_tstr;
	t_str	**result;
	t_str	**current_word;
	size_t	i;

	i = 0;
	temp_tstr.str = temp_str;
	temp_tstr.len = 0;
	result = (t_str **)ft_malloc(sizeof(t_str *) * (ft_cfwords(s, f) + 1));
	current_word = result;
	while (i < s.len || temp_tstr.len)
	{
		if (temp_tstr.len && (f(s.str[i]) || i == s.len))
		{
			*current_word++ = ft_tstrdup(temp_tstr);
			temp_tstr.len = 0;
		}
		if (!f(s.str[i]) && i < s.len)
			temp_str[temp_tstr.len++] = s.str[i];
		i = i < s.len ? i + 1 : i;
	}
	*current_word = NULL;
	return (result);
}
