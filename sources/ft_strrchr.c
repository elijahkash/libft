/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:57:33 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 16:58:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strrchr(const char *s, int c)
{
	return (strrchr(s, c));
}

#else

char		*ft_strrchr(const char *s, int c)
{
	const char *i;

	i = &s[ft_strlen(s)];
	while (i >= s)
	{
		if (*i == (char)c)
			return ((char *)i);
		i--;
	}
	return (NULL);
}

#endif
