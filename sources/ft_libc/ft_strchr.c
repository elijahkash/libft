/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:53:55 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 16:58:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strchr(const char *s, int c)
{
	return (strchr(s, c));
}

#else

char		*ft_strchr(const char *s, int c)
{
	const char *i;

	i = s;
	while (*i || c == '\0')
	{
		if (*i == (char)c)
			return ((char *)i);
		i++;
	}
	return (NULL);
}

#endif
