/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:46 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 18:52:07 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_garbage_collector.h>

#include <libft.h>

#include <unistd.h>
#include <stdlib.h>

static t_darr	g_mem_collector;
static void		*g_self_ptr = 0;

static void		ft_mem_error(void)
{
	write(FD_STDERR, MEMALLOC_ERR_MSG, MEMALLOC_ERR_MSG_LEN);
	exit(0);
}

void			ft_gc_init(void)
{
	g_mem_collector.item_size = (size_t *)malloc(sizeof(size_t));
	g_mem_collector.curlen = (size_t *)malloc(sizeof(size_t));
	g_mem_collector.max_len = (size_t *)malloc(sizeof(size_t));
	g_mem_collector.arr = (void **)malloc(sizeof(void *));
	if (!g_mem_collector.arr || !g_mem_collector.item_size ||
		!g_mem_collector.curlen || !g_mem_collector.max_len)
		ft_mem_error();
	*g_mem_collector.arr = malloc(sizeof(void *) * INIT_GC_SIZE);
	if (!*g_mem_collector.arr)
		ft_mem_error();
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
		*g_mem_collector.max_len *= 2;
		tmp = malloc(*g_mem_collector.max_len * *g_mem_collector.item_size);
		if (!tmp)
		{
			ft_gc_clean();
			ft_mem_error();
		}
		ft_memcpy(tmp, *g_mem_collector.arr,
					*g_mem_collector.curlen * *g_mem_collector.item_size);
		ft_swap(&tmp, g_mem_collector.arr, sizeof(void *));
		free(tmp);
		g_self_ptr = *g_mem_collector.arr;
	}
	tmp = malloc(size);
	if (!tmp)
	{
		ft_gc_clean();
		ft_mem_error();
	}
	darr_add(g_mem_collector, &tmp);
	return (tmp);
}

void			ft_free(void *ptr)
{
	void *tmp;

	if (!(tmp = darr_find(g_mem_collector, ptr)))
	{
		write(FD_STDERR, MEMFREE_ERR_MSG, MEMFREE_ERR_MSG_LEN);
		return ;
	}
	darr_pop_p(g_mem_collector, tmp);
	free(ptr);
}

void			ft_gc_clean(void)
{
	if (!g_self_ptr)
		ft_mem_error();
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
