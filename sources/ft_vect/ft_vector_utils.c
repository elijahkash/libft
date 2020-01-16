/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:55:16 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:31 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

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

void			vect_map(t_vect *restrict self, void (*func)(const void *))
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
