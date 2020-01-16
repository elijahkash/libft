/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:47:10 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:53 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline int	ft_strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

#else

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = (const unsigned char	*)s1;
	us2 = (const unsigned char	*)s2;
	while (us1[i] != 0 && us2[i] != 0)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (us1[i] == 0 && us2[i] != 0)
		return (us2[i] * -1);
	if (us2[i] == 0 && us1[i] != 0)
		return (us1[i]);
	return (0);
}

#endif
