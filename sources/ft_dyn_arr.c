/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:03 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 18:53:44 by mtrisha          ###   ########.fr       */
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

void		*darr(t_darr arr, size_t i)
{
	return ((char *)(arr.arr[0]) + i * *arr.item_size);
}

size_t		darr_i(t_darr arr, void *item)
{
	return ((item - *arr.arr) / *arr.item_size);
}

size_t		darr_l(t_darr arr)
{
	return (*arr.curlen);
}

void		*darr_eq(t_darr arr, size_t i, void *data)
{
	ft_memcpy(darr(arr, i), data, *arr.item_size);
	return (darr(arr, i));
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

void		*darr_pop(t_darr arr)
{
	(*arr.curlen)--;
	return (darr(arr, *arr.curlen));
}

void		*darr_pop_i(t_darr arr, size_t i)
{
	char	tmp[*arr.item_size];

	ft_memcpy(tmp, darr(arr, i), *arr.item_size);
	ft_memmove(darr(arr, i), darr(arr, i + 1),
				(*arr.curlen - i - 1) * *arr.item_size);
	ft_memcpy(darr(arr, *arr.curlen - 1), tmp, *arr.item_size);
	(*arr.curlen)--;
	return (darr(arr, *arr.curlen));
}

void		*darr_pop_p(t_darr arr, void *item)
{
	char	tmp[*arr.item_size];
	size_t	i;

	i = darr_i(arr, item);
	ft_memcpy(tmp, darr(arr, i), *arr.item_size);
	ft_memmove(darr(arr, i), darr(arr, i + 1),
				(*arr.curlen - i - 1) * *arr.item_size);
	ft_memcpy(darr(arr, *arr.curlen - 1), tmp, *arr.item_size);
	(*arr.curlen)--;
	return (darr(arr, *arr.curlen));
}

void		*darr_find(t_darr arr, void *data)
{
	size_t i;

	i = 0;
	while (i < *arr.curlen)
	{
		if (!ft_memcmp(darr(arr, i), &data, *arr.item_size))
			return (darr(arr, i));
		i++;
	}
	return (NULL);
}

void		darr_sort(t_darr arr, int (*cmp)(const void *, const void *),
						void (*sort)(void *, size_t, size_t,
									int (*cmp)(const void *, const void *)))
{
	sort(*arr.arr, *arr.curlen, *arr.item_size, cmp);
}
