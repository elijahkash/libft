/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:03 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/30 16:33:15 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

#include <libft.h>

void			vect_init(t_vect *restrict arr, size_t item_size,
												size_t init_len)
{
	if (!arr || !item_size || !init_len)
		ft_error_free_exit(ERR_DARR_MSG, MEMERR_CODE);
	arr->item_size = item_size;
	arr->curlen = 0;
	arr->max_len = init_len;
	arr->mem = ft_malloc(init_len * item_size);
}

void			vect_del(t_vect *restrict arr)
{
	ft_free(arr->mem);
	arr->mem = NULL;
	arr->curlen = 0;
	arr->item_size = 0;
	arr->max_len = 0;
}

inline void		vect_extend(t_vect *restrict arr, size_t n)
{
	size_t	oldsize;

	oldsize = arr->max_len;
	while (arr->curlen + n > arr->max_len)
		arr->max_len <<= 1;
	arr->mem = ft_remalloc(arr->mem, oldsize * arr->item_size,
									arr->max_len * arr->item_size);
}

void			vect_shrink(t_vect *restrict arr, size_t reserve)
{
	arr->mem = ft_remalloc(arr->mem, arr->max_len * arr->item_size,
									(arr->curlen + reserve) * arr->item_size);
	arr->max_len = (arr->curlen + reserve);
}

void			vect_clean(t_vect *restrict arr)
{
	ft_bzero(arr->mem, arr->max_len * arr->item_size);
	arr->curlen = 0;
}
