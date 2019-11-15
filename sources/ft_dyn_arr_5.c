/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:20:39 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/15 16:04:41 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

#include <libft.h>

size_t			darr_insert_uniq(t_darr arr, void *data,
							int (*cmp)(const void *, const void *))
{
	size_t	bot;
	size_t	top;
	int		tmp;

	if (!darr_l(arr))
		return ((int)darr_add(arr, data) * 0);
	top = darr_l(arr) - 1;
	bot = 0;
	while (bot != top)
	{
		tmp = cmp(data, darr(arr, bot + (top - bot) / 2));
		if (!tmp)
			return (0);
		if (tmp < 0)
			top = bot + (top - bot) / 2;
		else
			bot += (top - bot) / 2 + 1;
	}
	tmp = cmp(data, darr(arr, bot));
	if (tmp)
	{
		darr_add_i(arr, data, (tmp > 0) ? bot + 1 : bot);
		return (1 + bot + ((tmp > 0) ? 1 : 0));
	}
	return (0);
}

void			darr_trim(t_darr arr)
{
	*arr.arr = ft_remalloc(*arr.arr, *arr.max_len, *arr.curlen);
	*arr.max_len = *arr.curlen;
}
