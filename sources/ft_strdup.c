/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:43:32 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:07:54 by mtrisha          ###   ########.fr       */
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
