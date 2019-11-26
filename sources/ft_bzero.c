/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:13:17 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 15:49:53 by mtrisha          ###   ########.fr       */
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
