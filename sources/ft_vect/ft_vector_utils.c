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

void			*vect_find_back(t_vect *restrict self, void *data,
							int (*cmp)(const void *, const void *))
{
	register size_t i;

	i = self->curlen;
	while (i-- > 0)
	{
		if (UNLIKELY(!cmp(vect(self, i), &data)))
			return (vect(self, i));
	}
	return (NULL);
}

void			*vect_find_front(t_vect *restrict self, void *data,
							int (*cmp)(const void *, const void *))
{
	register size_t i;

	i = __SIZE_MAX__;
	while (++i < self->curlen)
	{
		if (UNLIKELY(!cmp(vect(self, i), &data)))
			return (vect(self, i));
	}
	return (NULL);
}

void			vect_map(t_vect *restrict self, void (*func)(void *))
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = self->mem;
	while (i < self->curlen)
	{
		func(ptr);
		i++;
		ptr += self->item_size;
	}
	return ;
}

void			vect_map_param(t_vect *restrict self,
							void (*func)(void *, size_t, void *), void *param)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = self->mem;
	while (i < self->curlen)
	{
		func(ptr, i, param);
		i++;
		ptr += self->item_size;
	}
	return ;
}
