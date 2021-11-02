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

#include "ft_deq.h"

#include "libft.h"

inline void		deq_rotate(t_deq *restrict self)
{
	deq_push_back(self, deq_pop_front(self));
}

inline void		deq_rev_rotate(t_deq *restrict self)
{
	deq_push_front(self, deq_pop_back(self));
}

void			*deq_find_front(t_deq *restrict self, void *data,
								int (*cmp)(const void *, const void *))
{
	size_t	i;

	i = 0;
	while (i < self->curlen)
	{
		if (cmp(data, deq(self, i)) == 0)
			return (deq(self, i));
		i++;
	}
	return (NULL);
}
