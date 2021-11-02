/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory_manager.h"

#include "libft.h"

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
