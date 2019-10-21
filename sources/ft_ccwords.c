/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:57:17 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/21 15:16:12 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_ccwords(const char *str, char c)
{
	size_t	count;
	int		is_word;

	if (!str)
		return (0);
	is_word = 0;
	count = 0;
	while (*str)
	{
		if (is_word && *str == c)
		{
			count++;
			is_word = 0;
		}
		if (*str != c && !is_word)
			is_word++;
		str++;
	}
	if (is_word)
		count++;
	return (count);
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
