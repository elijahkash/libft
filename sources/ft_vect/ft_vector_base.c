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

void			vect_init(t_vect *restrict self, size_t item_size,
												size_t init_len)
{
	if (!self || !item_size || !init_len)
		ft_error_free_exit(ERR_DARR_MSG, MEMERR_CODE);
	self->item_size = item_size;
	self->curlen = 0;
	self->max_len = init_len;
	self->mem = ft_malloc(init_len * item_size);
}

void			vect_del(t_vect *restrict self)
{
	ft_free(self->mem);
	ft_bzero(self, sizeof(t_vect));
}

inline void		vect_extend(t_vect *restrict self, size_t n)
{
	size_t	oldsize;

	oldsize = self->max_len;
	while (self->curlen + n > self->max_len)
		self->max_len <<= 1;
	self->mem = ft_remalloc(self->mem, oldsize * self->item_size,
									self->max_len * self->item_size);
}

void			vect_shrink(t_vect *restrict self, size_t reserve)
{
	self->mem = ft_remalloc(self->mem, self->max_len * self->item_size,
									(self->curlen + reserve) * self->item_size);
	self->max_len = (self->curlen + reserve);
}

void			vect_clean(t_vect *restrict self)
{
	ft_bzero(self->mem, self->max_len * self->item_size);
	self->curlen = 0;
}
