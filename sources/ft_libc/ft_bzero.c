/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:13:17 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:42 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline void	ft_bzero(void *s, size_t n)
{
	bzero(s, n);
}

#else

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

#endif
