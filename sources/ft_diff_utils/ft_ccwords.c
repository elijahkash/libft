/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:57:17 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/11 21:39:18 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

size_t	ft_ccwords(const char *restrict str, char c)
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
		is_word += (*str != c && is_word == 0) ? 1 : 0;
		str++;
	}
	return (count + ((is_word) ? 1 : 0));
}
