/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:48:34 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 20:54:33 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

#include <libft.h>

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
