/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:48:34 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/29 14:51:04 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

inline void		*vect_add(t_vect *restrict arr, void *data)
{
	if (UNLIKELY(arr->curlen == arr->max_len))
		vect_extend(arr, 1);
	return (ft_memcpy(vect(arr, (arr->curlen)++), data, arr->item_size));
}

inline void		*vect_add_n(t_vect *restrict arr, void *data, size_t n)
{
	if (UNLIKELY(arr->curlen + n == arr->max_len))
		vect_extend(arr, n);
	return (ft_memcpy(vect(arr, (arr->curlen)++), data, arr->item_size));
}

void			*vect_add_i(t_vect *restrict arr, void *data, size_t i)
{
	register void	*tmp;

	if (UNLIKELY(arr->curlen == arr->max_len))
		vect_extend(arr, 1);
	tmp = vect(arr, i);
	ft_memmove((char *)tmp + arr->item_size, tmp,
				((arr->curlen)++ - i) * arr->item_size);
	return (ft_memcpy(tmp, data, arr->item_size));
}

inline void		*vect_add_mem(t_vect *restrict arr, void *data, size_t len)
{
	return (vect_add(arr, ft_p(ft_memcpy(ft_malloc(len), data, len))));
}

