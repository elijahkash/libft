/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:57:33 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:00 by Kashnitskiy      ###   ########.fr       */
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
