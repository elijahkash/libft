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

inline void		*vect(t_vect *restrict self, size_t i)
{
	return ((self->mem) + i * self->item_size);
}

inline size_t	vect_i(t_vect *restrict self, void *item)
{
	return ((item - self->mem) / self->item_size);
}

inline void		*vect_top(t_vect *restrict self)
{
	return ((self->mem) + (self->curlen - 1) * self->item_size);
}

void			*vect_(t_vect *restrict self, long long int i)
{
	return ((i >= 0) ? vect(self, self->curlen - 1 - i) :
						vect(self, (i * -1) - 1));
}

inline void		*vect_eq(t_vect *restrict self, size_t i, void *data)
{
	return (ft_memcpy(vect(self, i), data, self->item_size));
}
