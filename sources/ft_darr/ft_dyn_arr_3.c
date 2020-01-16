/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:48:34 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:40 by Kashnitskiy      ###   ########.fr       */
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

	i = *arr.curlen;
	while (i > 0)
	{
		if (!ft_memcmp(darr(arr, i - 1), &data, *arr.item_size))
			return (darr(arr, i - 1));
		i--;
	}
	return (NULL);
}

size_t		darr_flfind_i(t_darr arr, void *data,
							int (*cmp)(const void *, const void *))
{
	size_t	bot;
	size_t	top;
	int		tmp;

	if (!darr_l(arr))
		return (0);
	top = darr_l(arr) - 1;
	bot = 0;
	while (bot != top)
	{
		tmp = cmp(data, darr(arr, bot + (top - bot) / 2));
		if (!tmp)
			return (1 + bot + (top - bot) / 2);
		if (tmp < 0)
			top = bot + (top - bot) / 2;
		else
			bot += (top - bot) / 2 + 1;
	}
	tmp = cmp(data, darr(arr, bot));
	return (tmp ? 0 : 1 + bot);
}

void		darr_sort(t_darr arr, int (*cmp)(const void *, const void *),
						void (*sort)(void *, size_t, size_t,
									int (*cmp)(const void *, const void *)))
{
	sort(*arr.arr, *arr.curlen, *arr.item_size, cmp);
}
