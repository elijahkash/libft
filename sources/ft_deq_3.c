/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:59:02 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/30 20:45:37 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

inline void		*deq_add_front(t_deq *restrict deque, void *data)
{
		//TODO: optimize
	if (UNLIKELY(deque->curlen == deque->max_len))
		deq_extend(deque, 1);
	if (UNLIKELY(((deque->front) -= (deque->curlen)++ ? 1 : 0) < 0))
		deque->front = deque->max_len - 1;
	return (ft_memcpy(deq(deque, deque->front), data, deque->item_size));
}

inline void		*deq_push_back(t_deq *restrict deque, void *data)
{
		//TODO: optimize
	if (UNLIKELY(deque->curlen == deque->max_len))
		deq_extend(deque, 1);
	if (UNLIKELY(((deque->back) += (deque->curlen)++ ? 1 : 0) ==
					deque->max_len))
		deque->back = 0;
	return (ft_memcpy(deq(deque, deque->back), data, deque->item_size));
}

inline void		*deq_push_front(t_deq *restrict deque)
{
	register void	*tmp;

	tmp = deq(deque, deque->front);
	if (UNLIKELY(((deque->front) += --(deque->curlen) ? 1 : 0) ==
					deque->max_len))
		deque->front = 0;
	return (tmp);
}

inline void		*deq_pop_back(t_deq *restrict deque)
{
	register void	*tmp;

	tmp = deq(deque, deque->back);
	if (UNLIKELY(((deque->back) -= --(deque->curlen) ? 1 : 0) < 0))
		deque->back = deque->max_len - 1;
	return (tmp);
}
