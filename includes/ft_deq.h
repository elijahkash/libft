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

#ifndef FT_DEQ_H
# define FT_DEQ_H

# include <string.h>

typedef struct	s_deq
{
	void *restrict	mem;
	size_t			item_size;
	size_t			curlen;
	size_t			max_len;
	size_t			front;
	size_t			back;
}				t_deq;

/*
** ft_deq_base.c
*/

void			deq_init(t_deq *restrict self, size_t item_size,
												size_t init_len);
void			deq_del(t_deq *restrict self);
void			deq_align_front(t_deq *restrict self);
void			deq_extend(t_deq *restrict self, size_t n);
void			deq_shrink(t_deq *restrict self, size_t reserve);

/*
** ft_deq_access.c
*/

void			*deq(t_deq *restrict self, size_t i);
void			*deq_front(t_deq *restrict self);
void			*deq_back(t_deq *restrict self);
void			*deq_(t_deq *restrict self, long long int i);
void			*deq_eq(t_deq *restrict self, size_t i, void *data);

/*
** ft_deq_pushpop.c
*/

void			*deq_push_front(t_deq *restrict self, void *data);
void			*deq_push_back(t_deq *restrict self, void *data);

void			*deq_pop_front(t_deq *restrict self);
void			*deq_pop_back(t_deq *restrict self);

/*
** ft_deq_utils.c
*/

void			deq_rotate(t_deq *restrict self);
void			deq_rev_rotate(t_deq *restrict self);

void			*deq_find_front(t_deq *restrict self, void *data,
								int (*cmp)(const void *, const void *));

/*
** void			deq_reset(t_deq *deq);
** void			deq_clean(t_deq *deq);
*/

#endif
