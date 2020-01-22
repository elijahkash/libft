/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:25:14 by Kashnitskiy       #+#    #+#             */
/*   Updated: 2020/01/22 18:54:44 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list_on_arr.h>

#include <libft.h>

void			alst_map(t_alst *restrict self, void (*func)(void *))
{
	size_t		cur;
	t_alst_item	tmp;

	cur = self->head;
	while (cur != ALST_SPEC_VALUE)
	{
		tmp = self->list[cur];
		func(alst(self, tmp.self));
		cur = tmp.next;
	}
}
