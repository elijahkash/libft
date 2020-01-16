/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:58:47 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:52 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

size_t	ft_strcmp_l(const char *s1, const char *s2)
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
			return (i);
		i++;
	}
	if (us1[i] == 0 && us2[i] != 0)
		return (i);
	if (us2[i] == 0 && us1[i] != 0)
		return (i);
	return (0);
}
