/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:20:39 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/29 17:18:07 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

void			*vect_find_back(t_vect *restrict arr, void *data,
							int (*cmp)(const void *, const void *))
{
	register size_t i;

	i = arr->curlen;
	while (i-- > 0)
	{
		if (UNLIKELY(!cmp(vect(arr, i), &data)))
			return (vect(arr, i));
	}
	return (NULL);
}

void			*vect_find_front(t_vect *restrict arr, void *data,
							int (*cmp)(const void *, const void *))
{
	register size_t i;

	i = __SIZE_MAX__;
	while (++i < arr->curlen)
	{
		if (UNLIKELY(!cmp(vect(arr, i), &data)))
			return (vect(arr, i));
	}
	return (NULL);
}

inline void		vect_sort(t_vect *restrict arr,
							int (*cmp)(const void *, const void *),
							void (*sort)(void *, size_t, size_t,
							int (*cmp)(const void *, const void *)))
{
	sort(arr->mem, arr->curlen, arr->item_size, cmp);
}

size_t			vect_bin_find(t_vect *restrict arr, void *data,
							int (*cmp)(const void *, const void *))
{
	size_t	bot;
	size_t	top;
	int		res;
	size_t	tmp;

	if (UNLIKELY(!arr->curlen))
		return (0);
	top = arr->curlen - 1;
	bot = 0;
	while (bot != top)
	{
		tmp = (top - bot) / 2;
		res = cmp(data, vect(arr, bot + tmp));
		if (!res)
			return (1 + bot + tmp);
		if (res < 0)
			top = bot + tmp;
		else
			bot += tmp + 1;
	}
	return (cmp(data, vect(arr, bot)) ? 0 : 1 + bot);
}

size_t			vect_insert_uniq(t_vect *restrict arr, void *data,
							int (*cmp)(const void *, const void *))
{
	size_t	bot;
	size_t	top;
	int		res;

	if (UNLIKELY(!arr->curlen))
		return (1 + (size_t)vect_add(arr, data) * 0);
	top = arr->curlen - 1;
	bot = 0;
	while (bot != top)
	{
		res = cmp(data, vect(arr, bot + (top - bot) / 2));
		if (!res)
			return (0);
		if (res < 0)
			top = bot + (top - bot) / 2;
		else
			bot += (top - bot) / 2 + 1;
	}
	res = cmp(data, vect(arr, bot));
	if (res)
	{
		vect_add_i(arr, data, (res > 0) ? bot + 1 : bot);
		return (1 + bot + ((res > 0) ? 1 : 0));
	}
	return (0);
}
