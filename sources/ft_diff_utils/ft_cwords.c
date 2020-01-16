/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cwords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:32:33 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:53 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

size_t	ft_cwords(const char *str, int (*f)(int c))
{
	size_t	count;
	int		is_word;

	if (!str)
		return (0);
	is_word = 0;
	count = 0;
	while (*str)
	{
		if (is_word && f(*str))
		{
			count++;
			is_word = 0;
		}
		if (!f(*str) && !is_word)
			is_word++;
		str++;
	}
	if (is_word)
		count++;
	return (count);
}
