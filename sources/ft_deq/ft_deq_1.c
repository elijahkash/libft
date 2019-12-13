/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:05:47 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/30 18:40:33 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

void			deq_init(t_deq *restrict deq, size_t item_size,
												size_t init_len)
{
	if (!deq || !item_size || !init_len)
		ft_error_free_exit(ERR_DARR_MSG, MEMERR_CODE);
	deq->item_size = item_size;
	deq->curlen = 0;
	deq->max_len = init_len;
	deq->front = 0;
	deq->back = 0;
	deq->mem = ft_malloc(init_len * item_size);
}

void			deq_del(t_deq *restrict deq)
{
	ft_free(deq->mem);
	deq->mem = NULL;
	deq->curlen = 0;
	deq->item_size = 0;
	deq->max_len = 0;
	deq->front = 0;
	deq->back = 0;
}

void			deq_align_front(t_deq *restrict deq)
{
	void *tmp;

	if (deq->front < deq->back)
	{
		ft_memmove(deq->mem, deq->mem + deq->front * deq->item_size,
					deq->curlen * deq->item_size);
		deq->front = 0;
		deq->back -= deq->front;
	}
	else
	{
		tmp = ft_memcpy(ft_malloc(++(deq->back) * deq->item_size), deq->mem,
						deq->back * deq->item_size);
		ft_memmove(deq->mem, deq->mem + deq->front * deq->item_size,
					(deq->max_len - deq->front) * deq->item_size);
		ft_memcpy(deq->mem + (deq->max_len - deq->front) * deq->item_size,
					tmp, deq->back * deq->item_size);
		deq->front = 0;
		deq->back = deq->curlen - 1;
		ft_free(tmp);
	}
}

void			deq_extend(t_deq *restrict deq, size_t n)
{
	size_t	oldsize;

	oldsize = deq->max_len;
	while (deq->curlen + n > deq->max_len)
		deq->max_len <<= 1;
	deq->mem = ft_remalloc(deq->mem, oldsize * deq->item_size,
									deq->max_len * deq->item_size);
	if (deq->front > deq->back)
	{
		ft_memmove(deq->mem + oldsize * deq->item_size, deq->mem,
					(deq->back + 1) * deq->item_size);
		deq->back += oldsize;
	}
}

void			deq_shrink(t_deq *restrict deq, size_t reserve)
{
	deq_align_front(deq);
	deq->mem = ft_remalloc(deq->mem, deq->max_len * deq->item_size,
									(deq->curlen + reserve) * deq->item_size);
	deq->max_len = (deq->curlen + reserve);
}
