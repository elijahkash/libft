/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:43:04 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/15 15:52:23 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>


#ifdef TURBO_MOD

void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	return (ft_gcremalloc(ptr, newsize + oldsize * 0));
}

#else

void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *newptr;

	if (newsize == oldsize)
		return (ptr);
	if (!(newptr = ft_memalloc(newsize)))
	{
		if (ptr)
			ft_free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		ft_memcpy(newptr, ptr, (oldsize < newsize) ? oldsize : newsize);
		ft_free(ptr);
	}
	return (newptr);
}

#endif
