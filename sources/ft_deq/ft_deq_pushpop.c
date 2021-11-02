/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deq.h"

#include "libft.h"

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
