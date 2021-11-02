/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_on_arr.h"

#include "libft.h"

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
