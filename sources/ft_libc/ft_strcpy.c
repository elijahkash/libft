/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:10:50 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:54 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strcpy(char *dst, const char *src)
{
	return (strcpy(dst, src));
}

#else

char		*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy((void *)dst, (void *)src, ft_strlen(src) + 1);
	return (dst);
}

#endif
