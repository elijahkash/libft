/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:58:47 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:19:09 by mtrisha          ###   ########.fr       */
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
