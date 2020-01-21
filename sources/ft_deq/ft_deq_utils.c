/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:42:15 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/21 18:43:15 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

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
