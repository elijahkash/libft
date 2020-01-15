/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:33:55 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/15 14:56:00 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

inline void		*vect_pop(t_vect *restrict self)
{
	return (vect(self, --(self->curlen)));
}

void			*vect_pop_i(t_vect *restrict self, size_t i)
{
	char					tmp[self->item_size];
	register void *restrict	ptr;

	ptr = vect(self, i);
	ft_memcpy(tmp, ptr, self->item_size);
	ft_memmove(ptr, ptr + self->item_size,
				(self->curlen - i - 1) * self->item_size);
	return (ft_memcpy(vect(self, --(self->curlen)), tmp, self->item_size));
}

void			*vect_pop_p(t_vect *restrict self, void *item)
{
	char					tmp[self->item_size];
	register void *restrict	ptr;
	register size_t			i;

	i = vect_i(self, item);
	ptr = vect(self, i);
	ft_memcpy(tmp, ptr, self->item_size);
	ft_memmove(ptr, ptr + self->item_size,
				(self->curlen - i - 1) * self->item_size);
	return (ft_memcpy(vect(self, --(self->curlen)), tmp, self->item_size));
}
