/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:01:59 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 16:58:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline void	*ft_memset(void *b, int c, size_t len)
{
	return (memset(b, c, len));
}

#else

void		*ft_memset(void *b, int c, size_t len)
{
	while (len)
		((char *)b)[--len] = (unsigned int)c;
	return (b);
}

#endif
