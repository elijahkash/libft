/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:43:49 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:57 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	return (strncat(s1, s2, n));
}

#else

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t tmp;
	size_t len;

	len = ft_strlen(s1);
	tmp = (n > ft_strlen(s2)) ? ft_strlen(s2) : n;
	ft_memcpy((void *)&(s1[len]), (void *)s2, tmp);
	s1[len + tmp] = '\0';
	return (s1);
}

#endif
