/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:03 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 20:54:40 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static void	darr_extend(t_darr arr)
{
	void	*tmp;

	*arr.max_len *= 2;
	tmp = ft_malloc(*arr.max_len * *arr.item_size);
	ft_memcpy(tmp, *arr.arr, *arr.curlen * *arr.item_size);
	ft_swap(&tmp, arr.arr, sizeof(void *));
	ft_free(tmp);
}

void		darr_init(t_darr *arr, size_t item_size, size_t init_len)
{
	if (!item_size || !init_len)
	{
		write(FD_STDERR, DARRINIT_ERR_MSG, DARRINIT_ERR_MSG_LEN);
		ft_gc_clean();
		exit(0);
	}
	arr->item_size = (size_t *)ft_malloc(sizeof(size_t));
	arr->curlen = (size_t *)ft_malloc(sizeof(size_t));
	arr->max_len = (size_t *)ft_malloc(sizeof(size_t));
	arr->arr = (void **)ft_malloc(sizeof(void *));
	*arr->item_size = item_size;
	*arr->curlen = 0;
	*arr->max_len = init_len;
	*arr->arr = ft_malloc(init_len * item_size);
}

void		darr_del(t_darr *arr)
{
	ft_free(*arr->arr);
	ft_free(arr->arr);
	ft_free(arr->item_size);
	ft_free(arr->max_len);
	ft_free(arr->curlen);
	arr->arr = NULL;
	arr->curlen = NULL;
	arr->item_size = NULL;
	arr->max_len = NULL;
}

void		*darr_add(t_darr arr, void *data)
{
	if (*arr.curlen == *arr.max_len)
		darr_extend(arr);
	ft_memcpy(darr(arr, *arr.curlen), data, *arr.item_size);
	(*arr.curlen)++;
	return (darr(arr, *arr.curlen - 1));
}

void		*darr_add_i(t_darr arr, void *data, size_t i)
{
	if (*arr.curlen == *arr.max_len)
		darr_extend(arr);
	ft_memmove(darr(arr, i + 1), darr(arr, i),
				(*arr.curlen - i) * *arr.item_size);
	ft_memcpy(darr(arr, i), data, *arr.item_size);
	(*arr.curlen)++;
	return (darr(arr, i));
}
