/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:33:55 by mtrisha           #+#    #+#             */
/*   Updated: 2020/03/01 14:01:51 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

#include <libft.h>

void		*darr_add_str(t_darr arr, void *data)
{
	void	*newstr;

	if (*arr.curlen == *arr.max_len)
		darr_extend(arr, 1);
	newstr = ft_malloc(ft_strlen(data) + 1);
	ft_strcpy(newstr, data);
	ft_memcpy(darr(arr, *arr.curlen), &newstr, *arr.item_size);
	(*arr.curlen)++;
	return (darr(arr, *arr.curlen - 1));
}

size_t		darr_setl(t_darr arr, size_t newlen)
{
	*arr.curlen = newlen;
	return (newlen);
}

void		*darr_clean(t_darr arr)
{
	ft_bzero(*arr.arr, *arr.curlen * *arr.item_size);
	*arr.curlen = 0;
	return (*arr.arr);
}

void		*darr_top(t_darr arr)
{
	return ((char *)(arr.arr[0]) + (*arr.curlen - 1) * *arr.item_size);
}

void		*darr_(t_darr arr, int i)
{
	if (i == 0)
		return (darr_top(arr));
	while (((i < 0) ? i * -1 : i) >= (int)darr_l(arr))
		i = (i > 0) ? i - (int)darr_l(arr) : i + (int)darr_l(arr);
	if (i >= 0)
		return (darr(arr, darr_l(arr) - 1 - i));
	else
		return (darr(arr, (i * -1) - 1));
}
