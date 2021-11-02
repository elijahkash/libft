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

static t_vect	g_mem_manager;

void			ft_memman_init(void)
{
	g_mem_manager.mem = malloc(sizeof(void *) * INIT_MM_SIZE);
	if (!g_mem_manager.mem)
		ft_error_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	g_mem_manager.item_size = sizeof(void *);
	g_mem_manager.curlen = 0;
	g_mem_manager.max_len = INIT_MM_SIZE;
	return ;
}

void			*ft_memman_malloc(size_t size)
{
	void	*tmp;
	size_t	oldsize;

	if (UNLIKELY(g_mem_manager.curlen == g_mem_manager.max_len))
	{
		oldsize = g_mem_manager.max_len;
		g_mem_manager.max_len += ((g_mem_manager.max_len <
			MM_MAX_INCREMENT) ? g_mem_manager.max_len : MM_MAX_INCREMENT);
		tmp = ft_nomm_remalloc(g_mem_manager.mem, oldsize * PTR_SIZE,
								g_mem_manager.max_len * PTR_SIZE);
		if (!tmp)
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		g_mem_manager.mem = tmp;
	}
	tmp = malloc(size);
	if (!tmp)
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	vect_add(&g_mem_manager, &tmp);
	return (tmp);
}

void			*ft_memman_remalloc(void *restrict ptr, size_t newsize)
{
	void *tmp;

	if ((tmp = vect_find_back(&g_mem_manager, ptr, ft_pcmp)))
		vect_pop_p(&g_mem_manager, tmp);
	tmp = realloc(ptr, newsize);
	if (!tmp)
	{
		ft_memdel(ptr);
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	}
	vect_add(&g_mem_manager, &tmp);
	return (tmp);
}

void			ft_memman_free(void *restrict ptr)
{
	void *tmp;

	if (!(tmp = vect_find_back(&g_mem_manager, ptr, ft_pcmp)))
	{
		ft_error_print(ERR_MEMFREE_MSG);
		return ;
	}
	(tmp == vect_top(&g_mem_manager)) ? vect_pop(&g_mem_manager) :
										vect_pop_p(&g_mem_manager, tmp);
	free(ptr);
	if (UNLIKELY(g_mem_manager.max_len > INIT_MM_SIZE &&
		g_mem_manager.curlen < (g_mem_manager.max_len >> 1) -
									MM_DIFF_FOR_TRIM))
	{
		tmp = ft_nomm_remalloc(g_mem_manager.mem, g_mem_manager.max_len *
							PTR_SIZE, PTR_SIZE * (g_mem_manager.max_len >> 1));
		if (!tmp)
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		g_mem_manager.mem = tmp;
		g_mem_manager.max_len >>= 1;
	}
}

void			ft_memman_clean(void)
{
	while (g_mem_manager.curlen > 0)
		free(*(void **)vect_pop(&g_mem_manager));
	free(g_mem_manager.mem);
	return ;
}

#endif
