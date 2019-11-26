/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:46 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:28:04 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory_manager.h>

#include <libft.h>

#include <stdlib.h>

static t_darr	g_mem_manager;
static void		*g_self_ptr = 0;

void			ft_memman_init(void)
{
	g_mem_manager.item_size = (size_t *)malloc(sizeof(size_t));
	g_mem_manager.curlen = (size_t *)malloc(sizeof(size_t));
	g_mem_manager.max_len = (size_t *)malloc(sizeof(size_t));
	g_mem_manager.arr = (void **)malloc(sizeof(void *));
	if (!g_mem_manager.arr || !g_mem_manager.item_size ||
		!g_mem_manager.curlen || !g_mem_manager.max_len)
		ft_error_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	*g_mem_manager.arr = malloc(sizeof(void *) * INIT_MM_SIZE);
	if (!*g_mem_manager.arr)
	{
		free(g_mem_manager.item_size);
		free(g_mem_manager.max_len);
		free(g_mem_manager.curlen);
		free(g_mem_manager.arr);
		ft_error_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	}
	*g_mem_manager.item_size = sizeof(void *);
	*g_mem_manager.curlen = 0;
	*g_mem_manager.max_len = INIT_MM_SIZE;
	g_self_ptr = *g_mem_manager.arr;
}

void			*ft_memman_malloc(size_t size)
{
	void	*tmp;

	if (*g_mem_manager.curlen == *g_mem_manager.max_len)
	{
		*g_mem_manager.max_len += ((*g_mem_manager.max_len <
			MM_MAX_INCREMENT) ? *g_mem_manager.max_len : MM_MAX_INCREMENT);
		tmp = malloc(*g_mem_manager.max_len * *g_mem_manager.item_size);
		if (!tmp)
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		ft_memcpy(tmp, *g_mem_manager.arr,
					*g_mem_manager.curlen * *g_mem_manager.item_size);
		ft_swap(&tmp, g_mem_manager.arr, sizeof(void *));
		free(tmp);
		g_self_ptr = *g_mem_manager.arr;
	}
	tmp = malloc(size);
	if (!tmp)
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	darr_add(g_mem_manager, &tmp);
	return (tmp);
}

void			*ft_memman_remalloc(void *ptr, size_t newsize)
{
	void *tmp;

	if ((tmp = darr_find(g_mem_manager, ptr)))
		darr_pop_p(g_mem_manager, tmp);
	tmp = realloc(ptr, newsize);
	if (!tmp)
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	darr_add(g_mem_manager, &tmp);
	return (tmp);
}

void			ft_memman_free(void *ptr)
{
	void *tmp;

	if (!(tmp = darr_find(g_mem_manager, ptr)))
	{
		ft_error_print(ERR_MEMFREE_MSG);
		return ;
	}
	darr_pop_p(g_mem_manager, tmp);
	free(ptr);
	if (*g_mem_manager.max_len > INIT_MM_SIZE &&
		*g_mem_manager.curlen < (*g_mem_manager.max_len >> 1) -
									MM_DIFF_FOR_TRIM)
	{
		tmp = malloc(sizeof(void *) * (*g_mem_manager.max_len >> 1));
		if (!tmp)
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		ft_memcpy(tmp, *g_mem_manager.arr,
				*g_mem_manager.curlen * sizeof(void *));
		free(g_self_ptr);
		g_self_ptr = tmp;
		*g_mem_manager.arr = tmp;
		*g_mem_manager.max_len = (*g_mem_manager.max_len >> 1);
	}
}

void			ft_memman_clean(void)
{
	while (*g_mem_manager.curlen > 0)
		free(*(void **)darr_pop(g_mem_manager));
	g_mem_manager.arr[0] = NULL;
	free(g_self_ptr);
	free(g_mem_manager.curlen);
	free(g_mem_manager.max_len);
	free(g_mem_manager.item_size);
	free(g_mem_manager.arr);
	g_self_ptr = NULL;
	return ;
}
