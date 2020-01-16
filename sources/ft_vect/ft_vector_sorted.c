/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:20:39 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:30 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

inline void		vect_sort(t_vect *restrict self,
							int (*cmp)(const void *, const void *),
							void (*sort)(void *, size_t, size_t,
							int (*cmp)(const void *, const void *)))
{
	sort(self->mem, self->curlen, self->item_size, cmp);
}

size_t			vect_bin_find(t_vect *restrict self, void *data,
							int (*cmp)(const void *, const void *))
{
	size_t	bot;
	size_t	top;
	int		res;
	size_t	tmp;

	if (UNLIKELY(!self->curlen))
		return (0);
	top = self->curlen - 1;
	bot = 0;
	while (bot != top)
	{
		tmp = (top - bot) / 2;
		res = cmp(data, vect(self, bot + tmp));
		if (!res)
			return (1 + bot + tmp);
		if (res < 0)
			top = bot + tmp;
		else
			bot += tmp + 1;
	}
	return (cmp(data, vect(self, bot)) ? 0 : 1 + bot);
}

size_t			vect_insert_uniq(t_vect *restrict self, void *data,
							int (*cmp)(const void *, const void *))
{
	size_t	bot;
	size_t	top;
	int		res;

	if (UNLIKELY(!self->curlen))
		return (1 + (size_t)vect_add(self, data) * 0);
	top = self->curlen - 1;
	bot = 0;
	while (bot != top)
	{
		res = cmp(data, vect(self, bot + (top - bot) / 2));
		if (!res)
			return (0);
		if (res < 0)
			top = bot + (top - bot) / 2;
		else
			bot += (top - bot) / 2 + 1;
	}
	res = cmp(data, vect(self, bot));
	if (res)
	{
		vect_add_i(self, data, (res > 0) ? bot + 1 : bot);
		return (1 + bot + ((res > 0) ? 1 : 0));
	}
	return (0);
}
