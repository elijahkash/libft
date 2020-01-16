/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:48:37 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:28 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

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
