/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:42:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/14 18:52:36 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deq.h>

#include <libft.h>

inline void		deq_rotate(t_deq *restrict deque)
{
	deq_push_back(deque, deq_pop_front(deque));
}

inline void		deq_rev_rotate(t_deq *restrict deque)
{
	deq_push_front(deque, deq_pop_back(deque));
}

void			*deq_find_front(t_deq *restrict deque, void *data,
								int (*cmp)(const void *, const void *))
{
	size_t	i;

	i = 0;
	while (i < deque->curlen)
	{
		if (cmp(data, deq(deque, i)) == 0)
			return (deq(deque, i));
		i++;
	}
	return (NULL);
}
