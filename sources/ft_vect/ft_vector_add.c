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

#include "ft_vector.h"

#include "libft.h"

inline void		*vect_add(t_vect *restrict self, void *data)
{
	if (UNLIKELY(self->curlen == self->max_len))
		vect_extend(self, 1);
	return (ft_memcpy(vect(self, (self->curlen)++), data, self->item_size));
}

inline void		*vect_add_n(t_vect *restrict self, void *data, size_t n)
{
	if (UNLIKELY(self->curlen + n >= self->max_len))
		vect_extend(self, n);
	ft_memcpy(vect(self, self->curlen), data, self->item_size * n);
	self->curlen += n;
	return (vect_top(self));
}

void			*vect_add_i(t_vect *restrict self, void *data, size_t i)
{
	register void *restrict	tmp;

	if (UNLIKELY(self->curlen == self->max_len))
		vect_extend(self, 1);
	tmp = vect(self, i);
	ft_memmove(tmp + self->item_size, tmp,
				((self->curlen)++ - i) * self->item_size);
	return (ft_memcpy(tmp, data, self->item_size));
}

inline void		*vect_add_mem(t_vect *restrict self, void *data, size_t len)
{
	return (vect_add(self, ft_p(ft_memcpy(ft_malloc(len), data, len))));
}
