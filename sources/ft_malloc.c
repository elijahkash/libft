/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:30:21 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/01 17:22:19 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory_manager.h>

#include <libft.h>

#include <stdlib.h>

#ifdef USE_MEM_MAN

void			*ft_malloc(size_t size)
{
	return (ft_memman_malloc(size));
}

#else

# ifdef XMALLOC_MOD

void			*ft_malloc(size_t size)
{
	register void	*tmp;

	if (!(tmp = malloc(size)))
		ft_error_exit(ERR_MEMALLOC_MSG, 0);
	return (tmp);
}

# else

inline void		*ft_malloc(size_t size)
{
	return (malloc(size));
}

# endif

#endif
