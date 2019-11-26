/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:36:11 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 16:58:35 by mtrisha          ###   ########.fr       */
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
