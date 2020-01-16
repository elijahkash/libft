/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:53:55 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:52 by Kashnitskiy      ###   ########.fr       */
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
