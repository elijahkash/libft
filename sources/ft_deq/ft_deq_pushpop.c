/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_pushpop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:59:02 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/21 18:43:14 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

inline void		*deq_push_front(t_deq *restrict self, void *data)
{
	if (UNLIKELY(self->curlen == self->max_len))
		deq_extend(self, 1);
	if (UNLIKELY(((self->front) -= (self->curlen)++ ? 1 : 0) == __SIZE_MAX__))
		self->front = self->max_len - 1;
	return (ft_memcpy(self->mem + self->front * self->item_size,
					data, self->item_size));
}

inline void		*deq_push_back(t_deq *restrict self, void *data)
{
	if (UNLIKELY(self->curlen == self->max_len))
		deq_extend(self, 1);
	if (UNLIKELY(((self->back) += (self->curlen)++ ? 1 : 0) ==
					self->max_len))
		self->back = 0;
	return (ft_memcpy(self->mem + self->back * self->item_size,
					data, self->item_size));
}

inline void		*deq_pop_front(t_deq *restrict self)
{
	register void	*tmp;

	tmp = self->mem + self->front * self->item_size;
	if (UNLIKELY(((self->front) += --(self->curlen) ? 1 : 0) ==
					self->max_len))
		self->front = 0;
	return (tmp);
}

inline void		*deq_pop_back(t_deq *restrict self)
{
	register void	*tmp;

	tmp = self->mem + self->back * self->item_size;
	if (UNLIKELY(((self->back) -= --(self->curlen) ? 1 : 0) == __SIZE_MAX__))
		self->back = self->max_len - 1;
	return (tmp);
}
