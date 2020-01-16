/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:01:02 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:30 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

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
