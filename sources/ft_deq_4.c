/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:42:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/30 20:47:13 by mtrisha          ###   ########.fr       */
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
