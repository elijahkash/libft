/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:43:32 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:21 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

#ifdef USE_MEM_MAN

char		*ft_strdup(const char *s1)
{
	char *str;

	str = ft_strnew(ft_strlen(s1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, ft_strlen(s1));
	return (str);
}

#else

# ifdef USE_LIBC

inline char	*ft_strdup(const char *s1)
{
	return (strdup(s1));
}

# else

char		*ft_strdup(const char *s1)
{
	char *str;

	str = ft_strnew(ft_strlen(s1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, ft_strlen(s1));
	return (str);
}

# endif

#endif
