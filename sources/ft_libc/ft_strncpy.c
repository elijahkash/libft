/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:19:38 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:59 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	return (strncpy(dst, src, len));
}

#else

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t tmp;

	tmp = (len > ft_strlen(src)) ? ft_strlen(src) : len;
	ft_bzero(dst, len);
	ft_memcpy(dst, src, tmp);
	return (dst);
}

#endif
