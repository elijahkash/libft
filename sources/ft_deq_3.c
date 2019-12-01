/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:59:02 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/01 16:08:56 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

inline void		*deq_push_front(t_deq *restrict deque, void *data)
{
	if (UNLIKELY(deque->curlen == deque->max_len))
		deq_extend(deque, 1);
	if (UNLIKELY(((deque->front) -= (deque->curlen)++ ? 1 : 0) == __SIZE_MAX__))
		deque->front = deque->max_len - 1;
	return (ft_memcpy(deque->mem + deque->front * deque->item_size,
					data, deque->item_size));
}

inline void		*deq_push_back(t_deq *restrict deque, void *data)
{
	if (UNLIKELY(deque->curlen == deque->max_len))
		deq_extend(deque, 1);
	if (UNLIKELY(((deque->back) += (deque->curlen)++ ? 1 : 0) ==
					deque->max_len))
		deque->back = 0;
	return (ft_memcpy(deque->mem + deque->back * deque->item_size,
					data, deque->item_size));
}

inline void		*deq_pop_front(t_deq *restrict deque)
{
	register void	*tmp;

	tmp = deque->mem + deque->front * deque->item_size;
	if (UNLIKELY(((deque->front) += --(deque->curlen) ? 1 : 0) ==
					deque->max_len))
		deque->front = 0;
	return (tmp);
}

inline void		*deq_pop_back(t_deq *restrict deque)
{
	register void	*tmp;

	tmp = deque->mem + deque->back * deque->item_size;
	if (UNLIKELY(((deque->back) -= --(deque->curlen) ? 1 : 0) == __SIZE_MAX__))
		deque->back = deque->max_len - 1;
	return (tmp);
}
