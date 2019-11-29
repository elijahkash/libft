/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:48:37 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/29 14:13:40 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

inline void		*vect(t_vect *restrict arr, size_t i)
{
	return ((char *)(arr->mem) + i * arr->item_size);
}

inline size_t	vect_i(t_vect *restrict arr, void *item)
{
	return ((item - arr->mem) / arr->item_size);
}

inline void		*vect_top(t_vect *restrict arr)
{
	return ((char *)(arr->mem) + (arr->curlen - 1) * arr->item_size);
}

void			*vect_(t_vect *restrict arr, long long int i)
{
	if (UNLIKELY(i == 0))
		return (vect_top(arr));
	while (UNLIKELY((size_t)ABS_LL(i) >= arr->curlen))
		i += (i > 0) ? arr->curlen * -1 : arr->curlen;
	return ((i >= 0) ? vect(arr, arr->curlen - 1 - i) :
						vect(arr, (i * -1) - 1));
}

inline void		*vect_eq(t_vect *restrict arr, size_t i, void *data)
{
	return (ft_memcpy(vect(arr, i), data, arr->item_size));
}
