/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:46 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/15 17:15:39 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_garbage_collector.h>

#include <libft.h>

#include <stdlib.h>

static t_darr	g_mem_collector;
static void		*g_self_ptr = 0;

void			ft_gc_init(void)
{
	g_mem_collector.item_size = (size_t *)malloc(sizeof(size_t));
	g_mem_collector.curlen = (size_t *)malloc(sizeof(size_t));
	g_mem_collector.max_len = (size_t *)malloc(sizeof(size_t));
	g_mem_collector.arr = (void **)malloc(sizeof(void *));
	if (!g_mem_collector.arr || !g_mem_collector.item_size ||
		!g_mem_collector.curlen || !g_mem_collector.max_len)
		ft_error_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	*g_mem_collector.arr = malloc(sizeof(void *) * INIT_GC_SIZE);
	if (!*g_mem_collector.arr)
	{
		free(g_mem_collector.item_size);
		free(g_mem_collector.max_len);
		free(g_mem_collector.curlen);
		free(g_mem_collector.arr);
		ft_error_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	}
	*g_mem_collector.item_size = sizeof(void *);
	*g_mem_collector.curlen = 0;
	*g_mem_collector.max_len = INIT_GC_SIZE;
	g_self_ptr = *g_mem_collector.arr;
}

void			*ft_malloc(size_t size)
{
	void	*tmp;

	if (*g_mem_collector.curlen == *g_mem_collector.max_len)
	{
		*g_mem_collector.max_len += ((*g_mem_collector.max_len < 1024) ?
			*g_mem_collector.max_len : 1024);
		tmp = malloc(*g_mem_collector.max_len * *g_mem_collector.item_size);
		if (!tmp)
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		ft_memcpy(tmp, *g_mem_collector.arr,
					*g_mem_collector.curlen * *g_mem_collector.item_size);
		ft_swap(&tmp, g_mem_collector.arr, sizeof(void *));
		free(tmp);
		g_self_ptr = *g_mem_collector.arr;
	}
	tmp = malloc(size);
	if (!tmp)
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	darr_add(g_mem_collector, &tmp);
	return (tmp);
}

void			*ft_gcremalloc(void *ptr, size_t newsize)
{
	void *tmp;

	if ((tmp = darr_find(g_mem_collector, ptr)))
		darr_pop_p(g_mem_collector, tmp);
	tmp = realloc(ptr, newsize);
	if (!tmp)
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	darr_add(g_mem_collector, &tmp);
	return (tmp);
}

void			ft_free(void *ptr)
{
	void *tmp;

	if (!(tmp = darr_find(g_mem_collector, ptr)))
	{
		ft_error_print(ERR_MEMFREE_MSG);
		return ;
	}
	darr_pop_p(g_mem_collector, tmp);
	free(ptr);
	if (*g_mem_collector.max_len > 128 &&
		*g_mem_collector.curlen < (*g_mem_collector.max_len >> 1) - 64)
	{
		tmp = malloc(sizeof(void *) * (*g_mem_collector.max_len >> 1));
		if (!tmp)
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		ft_memcpy(tmp, *g_mem_collector.arr,
				*g_mem_collector.curlen * sizeof(void *));
		free(g_self_ptr);
		g_self_ptr = tmp;
		*g_mem_collector.arr = tmp;
		*g_mem_collector.max_len = (*g_mem_collector.max_len >> 1);
	}
}

void			ft_gc_clean(void)
{
	while (*g_mem_collector.curlen > 0)
		free(*(void **)darr_pop(g_mem_collector));
	g_mem_collector.arr[0] = NULL;
	free(g_self_ptr);
	free(g_mem_collector.curlen);
	free(g_mem_collector.max_len);
	free(g_mem_collector.item_size);
	free(g_mem_collector.arr);
	g_self_ptr = NULL;
	return ;
}
