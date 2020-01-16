/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:36:11 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:51 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strcat(char *s1, const char *s2)
{
	return (strcat(s1, s2));
}

#else

char		*ft_strcat(char *s1, const char *s2)
{
	ft_memcpy(s1 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s1);
}

#endif
