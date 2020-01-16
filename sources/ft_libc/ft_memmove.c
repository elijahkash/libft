/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:30:11 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:49 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline void	*ft_memmove(void *dst, const void *src, size_t len)
{
	return (memmove(dst, src, len));
}

#else

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (dst == src && dst == NULL)
		return (NULL);
	if (dst >= src)
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

#endif
