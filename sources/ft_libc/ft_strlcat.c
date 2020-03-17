/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:32:10 by mtrisha           #+#    #+#             */
/*   Updated: 2020/03/17 14:22:19 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#if defined USE_LIBC && ! defined __linux__

inline size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	return (strlcat(dst, src, size));
}

#else

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size && dst[i] != '\0')
		++i;
	j = 0;
	while (src[j] != '\0' && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

#endif
