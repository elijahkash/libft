/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:46 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 22:54:00 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_garbage_collector.h>

#include <libft.h>

#include <unistd.h>
#include <stdlib.h>

static t_darr	g_mem_collector;

static void		ft_mem_error(void)
{
	write(FD_STDERR, MEMALLOC_ERR_MSG, MEMALLOC_ERR_MSG_LEN);
	exit(0);
}

void			ft_init_gb(void)
{
	ft_bzero(&g_mem_collector, sizeof(t_darr));
	darr_init(&g_mem_collector, sizeof(void *), INIT_GC_SIZE);
}

void			*ft_malloc(size_t size)
{
	void *res;

	res = malloc(size);
	if (!res)
	{
		ft_gb_clean();
		ft_mem_error();
	}
	if (!g_mem_collector.arr)
	{
		g_mem_collector.arr = res;
		g_mem_collector.arr = res;
	}
	else
		darr_add(g_mem_collector, res);
	return (res);
}

void			ft_free(void **ptr)
{
	void *tmp;

	if (!(tmp = darr_find(g_mem_collector, *ptr))) //TODO here
	{
		write(FD_STDERR, MEMFREE_ERR_MSG, MEMFREE_ERR_MSG_LEN);
		return ;
	}
	tmp = darr_pop_p(g_mem_collector, tmp);
	free(tmp);
	*ptr = NULL;
}

void			ft_gb_clean(void)
{
	void *tmp;

	if (!g_mem_collector.arr)
		ft_mem_error();
	while (g_mem_collector.curlen > 1)
		free(darr_pop(g_mem_collector));
	tmp = darr_pop(g_mem_collector);
	ft_bzero(&g_mem_collector, sizeof(t_darr));
	free(tmp);
	return ;
}
