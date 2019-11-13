/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:20:39 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/13 20:13:28 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

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
			return (bot + (top - bot) / 2);
		if (tmp < 0)
			top = bot + (top - bot) / 2 - 1;
		else
			bot += (top - bot) / 2 + 1;
	}
	tmp = cmp(data, darr(arr, bot));
	if (tmp)
	{
		darr_add_i(arr, data, (tmp > 0) ? bot + 1 : bot);
		return ((tmp > 0) ? bot + 1 : bot);
	}
	return (bot);
}

int				darr_flfind_i_int(t_darr arr, void *data,
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
			return (bot + (top - bot) / 2);
		if (tmp < 0)
			top = bot + (top - bot) / 2 - 1;
		else
			bot += (top - bot) / 2 + 1;
	}
	tmp = cmp(data, darr(arr, bot));
	return (tmp ? 0 - bot - 1 : bot);
}

size_t			darr_insert_i(t_darr arr, void *data, size_t i,
								int (*cmp)(const void *, const void *))
{
	int		tmp;

	tmp = cmp(data, darr(arr, i));
	if (tmp)
	{
		darr_add_i(arr, data, (tmp > 0) ? i + 1 : i);
		return ((tmp > 0) ? i + 1 : i);
	}
	else
		darr_add_i(arr, data, i);
	return (i);
}
