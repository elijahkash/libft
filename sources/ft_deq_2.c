/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:55:30 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/02 15:12:51 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

inline void		*deq(t_deq *restrict deq, size_t i)
{
	return (deq->mem + (i + deq->front - ((i >= (deq->max_len - deq->front)) ?
										deq->max_len : 0)) * deq->item_size);
}

inline void		*deq_front(t_deq *restrict deq)
{
	return (deq->mem + deq->front * deq->item_size);
}

inline void		*deq_back(t_deq *restrict deq)
{
	return (deq->mem + deq->back * deq->item_size);
}

inline void		*deq_(t_deq *restrict deque, long long int i)
{
	return (deq(deque, i + deque->curlen * (i < 0)));
}

inline void		*deq_eq(t_deq *restrict deque, size_t i, void *data)
{
	return (ft_memcpy(deq(deque, i), data, deque->item_size));
}
