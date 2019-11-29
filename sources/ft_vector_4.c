/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:33:55 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/29 17:31:24 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

inline void		*vect_pop(t_vect *restrict arr)
{
	return (vect(arr, --(arr->curlen)));
}

void		*vect_pop_i(t_vect *restrict arr, size_t i)
{
	char			tmp[arr->item_size];
	register void	*ptr;

	ptr = vect(arr, i);
	ft_memcpy(tmp, ptr, arr->item_size);
	ft_memmove(ptr, (char *)ptr + arr->item_size,
				(arr->curlen - i - 1) * arr->item_size);
	return (ft_memcpy(vect(arr, --(arr->curlen)), tmp, arr->item_size));
}

void		*vect_pop_p(t_vect *restrict arr, void *item)
{
	char			tmp[arr->item_size];
	register void	*ptr;
	register size_t	i;

	i = vect_i(arr, item);
	ptr = vect(arr, i);
	ft_memcpy(tmp, ptr, arr->item_size);
	ft_memmove(ptr, (char *)ptr + arr->item_size,
				(arr->curlen - i - 1) * arr->item_size);
	return (ft_memcpy(vect(arr, --(arr->curlen)), tmp, arr->item_size));
}
