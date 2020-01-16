/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:43:04 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:22 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory_manager.h>

#include <libft.h>

#include <stdlib.h>

#ifdef USE_MEM_MAN

inline void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	return ((LIKELY(newsize != oldsize)) ?
			ft_memman_remalloc(ptr, newsize) : ptr);
}

#else

void		*ft_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *newptr;

	if (newsize == oldsize)
		return (ptr);
	if (!(newptr = ft_malloc(newsize)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, (oldsize < newsize) ? oldsize : newsize);
		ft_free(ptr);
	}
	return (newptr);
}

#endif

#ifdef USE_LIBC

inline void	*ft_nomm_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	return (realloc(ptr, newsize + oldsize * 0));
}

#else

void		*ft_nomm_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *newptr;

	if (newsize == oldsize)
		return (ptr);
	if (!(newptr = malloc(newsize)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, (oldsize < newsize) ? oldsize : newsize);
		free(ptr);
	}
	return (newptr);
}

#endif
