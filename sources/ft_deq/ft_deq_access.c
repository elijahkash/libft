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

inline void		*deq(t_deq *restrict self, size_t i)
{
	return (self->mem + (i + self->front - ((i >= (self->max_len - self->front))
				? self->max_len : 0)) * self->item_size);
}

inline void		*deq_front(t_deq *restrict self)
{
	return (self->mem + self->front * self->item_size);
}

inline void		*deq_back(t_deq *restrict self)
{
	return (self->mem + self->back * self->item_size);
}

inline void		*deq_(t_deq *restrict self, long long int i)
{
	return (deq(self, i + self->curlen * (i < 0)));
}

inline void		*deq_eq(t_deq *restrict self, size_t i, void *data)
{
	return (ft_memcpy(deq(self, i), data, self->item_size));
}
