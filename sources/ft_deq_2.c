/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:55:30 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/30 20:49:59 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

inline void		*deq(t_deq *restrict deq, size_t i)
{
	if (deq->front < deq->back || (i < (deq->max_len - deq->front)))
		return (deq->mem + (deq->front + i) * deq->item_size);
	else
		return (deq->mem + (i - deq->max_len + deq->front) * deq->item_size);
}

inline void		*deq_front(t_deq *restrict deq)
{
	return (deq->mem + deq->front * deq->item_size);
}

inline void		*deq_back(t_deq *restrict deq)
{
	return (deq->mem + deq->back * deq->item_size);
}

void			*deq_(t_deq *restrict deque, long long int i)
{
	if (UNLIKELY(i == 0))
		return (deq_front(deque));
	while (UNLIKELY((size_t)ABS_LL(i) >= deque->curlen))
		i += (i > 0) ? deque->curlen * -1 : deque->curlen;
	return ((i >= 0) ? deq(deque, i) :
						deq(deque, deque->curlen + i - 1));
}

inline void		*deq_eq(t_deq *restrict deque, size_t i, void *data)
{
	return (ft_memcpy(deq(deque, i), data, deque->item_size));
}
