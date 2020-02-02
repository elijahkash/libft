/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:10:56 by mtrisha           #+#    #+#             */
/*   Updated: 2020/02/02 12:05:08 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <string.h>

typedef struct	s_vector
{
	void *restrict	mem;
	size_t			item_size;
	size_t			curlen;
	size_t			max_len;
}				t_vect;

/*
** ft_vector_base.c
*/

void			vect_init(t_vect *restrict self, size_t item_size,
												size_t init_len);
void			vect_del(t_vect *restrict self);
void			vect_extend(t_vect *restrict self, size_t n);
void			vect_shrink(t_vect *restrict self, size_t reserve);
void			vect_clean(t_vect *self);

/*
** ft_vector_access.c
*/

void			*vect(t_vect *restrict self, size_t i);
size_t			vect_i(t_vect *restrict self, void *item);
void			*vect_top(t_vect *restrict self);
void			*vect_(t_vect *restrict self, long long int i);
void			*vect_eq(t_vect *restrict self, size_t i, void *data);

/*
** ft_vector_add.c
*/

void			*vect_add(t_vect *restrict self, void *data);
void			*vect_add_i(t_vect *restrict self, void *data, size_t i);
void			*vect_add_n(t_vect *restrict self, void *data, size_t n);
void			*vect_add_mem(t_vect *restrict self, void *data, size_t len);

/*
** ft_vector_pop.c
*/

void			*vect_pop(t_vect *restrict self);
void			*vect_pop_i(t_vect *restrict self, size_t i);
void			*vect_pop_p(t_vect *restrict self, void *item);

/*
** ft_vector_utils.c
*/

void			*vect_find_back(t_vect *restrict self, void *data,
							int (*cmp)(const void *, const void *));
void			*vect_find_front(t_vect *restrict self, void *data,
							int (*cmp)(const void *, const void *));
void			vect_map(t_vect *restrict self, void (*func)(void *));
void			vect_map_param(t_vect *restrict self,
							void (*func)(void *, size_t, void *), void *param);

/*
** ft_vector_sorted.c
*/

void			vect_sort(t_vect *restrict self,
							int (*cmp)(const void *, const void *),
							void (*sort)(void *, size_t, size_t,
							int (*cmp)(const void *, const void *)));
size_t			vect_bin_find(t_vect *self, void *data,
							int (*cmp)(const void *, const void *));
size_t			vect_insert_uniq(t_vect *self, void *data,
							int (*cmp)(const void *, const void *));

#endif
