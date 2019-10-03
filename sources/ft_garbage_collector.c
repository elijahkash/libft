/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:46 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 22:08:54 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_garbage_collector.h>

#include <libft.h>

#include <unistd.h>
#include <stdlib.h>

static t_darr	g_mem_collector;

static void	ft_mem_error(void)
{
	write(FD_STDERR, MEMALLOC_ERR_MSG, MEMALLOC_ERR_MSG_LEN);
	exit(0);
}

void		ft_init_gb(void)
{
	ft_bzero(&g_mem_collector, sizeof(t_darr));
	darr_init(&g_mem_collector, sizeof(void *), 128);
}

void		*ft_malloc(size_t size)
{
}

void		ft_free(void *ptr)
{
	void *tmp;

}

void		ft_gb_clean(void)
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
