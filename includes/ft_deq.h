/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:08:54 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/01 17:16:44 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQ_H
# define FT_DEQ_H

# include <string.h>

typedef struct	s_deq
{
	void	*mem;
	size_t	front;
	size_t	back;
	size_t	item_size;
	size_t	curlen;
	size_t	max_len;
}				t_deq;

void			deq_init(t_deq *restrict deq, size_t item_size,
												size_t init_len);
void			deq_del(t_deq *restrict deq);
void			deq_align_front(t_deq *restrict deq);
void			deq_extend(t_deq *restrict deq, size_t n);
void			deq_shrink(t_deq *restrict deq, size_t reserve);

void			*deq(t_deq *restrict deq, size_t i);
void			*deq_front(t_deq *restrict deq);
void			*deq_back(t_deq *restrict deq);
void			*deq_(t_deq *restrict deq, long long int i);
void			*deq_eq(t_deq *restrict deque, size_t i, void *data);

void			*deq_push_front(t_deq *restrict deque, void *data);
void			*deq_push_back(t_deq *restrict deque, void *data);

void			*deq_pop_front(t_deq *restrict deque);
void			*deq_pop_back(t_deq *restrict deque);

void			deq_rotate(t_deq *restrict deque);
void			deq_rev_rotate(t_deq *restrict deque);

/*
** void			deq_reset(t_deq *deq);
** void			deq_clean(t_deq *deq);
*/

#endif
