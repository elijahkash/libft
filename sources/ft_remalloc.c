/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:43:04 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/10 17:46:04 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *newptr;

	if (!(newptr = ft_memalloc(newsize)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(newptr, ptr, oldsize);
	free(ptr);
	return (newptr);
}
