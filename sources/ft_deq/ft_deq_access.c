/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:55:30 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/21 18:43:13 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

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
