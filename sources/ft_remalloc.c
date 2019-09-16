/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:43:04 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/16 13:39:16 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *newptr;

	if (newsize == oldsize)
		return (ptr);
	if (!(newptr = ft_memalloc(newsize)))
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		ft_memcpy(newptr, ptr, (oldsize < newsize) ? oldsize : newsize);
		free(ptr);
	}
	return (newptr);
}
