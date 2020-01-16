/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:14:22 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:01 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline char	*ft_strstr(const char *haystack, const char *needle)
{
	return (strstr(haystack, needle));
}

#else

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			check = 1;
			while (needle[++j] != 0)
			{
				check = (needle[j] == haystack[i + j]) ? 1 : 0;
				if (!check)
					break ;
			}
			if (check)
				return ((char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}

#endif
