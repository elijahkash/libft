/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:01:59 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:50 by Kashnitskiy      ###   ########.fr       */
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
