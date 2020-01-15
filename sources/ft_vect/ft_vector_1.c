/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:03 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/09 18:34:21 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

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
	self->mem = NULL;
	self->curlen = 0;
	self->item_size = 0;
	self->max_len = 0;
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