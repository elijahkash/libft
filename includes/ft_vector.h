/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:10:56 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/09 12:52:33 by mtrisha          ###   ########.fr       */
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

void			vect_init(t_vect *restrict arr, size_t item_size,
												size_t init_len);
void			vect_del(t_vect *restrict arr);
void			vect_extend(t_vect *restrict arr, size_t n);
void			vect_shrink(t_vect *restrict arr, size_t reserve);
void			vect_clean(t_vect *arr);

void			*vect(t_vect *restrict arr, size_t i);
size_t			vect_i(t_vect *restrict arr, void *item);
void			*vect_top(t_vect *restrict arr);
void			*vect_(t_vect *restrict arr, long long int i);
void			*vect_eq(t_vect *restrict arr, size_t i, void *data);

void			*vect_add(t_vect *restrict arr, void *data);
void			*vect_add_i(t_vect *restrict arr, void *data, size_t i);
void			*vect_add_n(t_vect *restrict arr, void *data, size_t n);
void			*vect_add_mem(t_vect *restrict arr, void *data, size_t len);

void			*vect_pop(t_vect *restrict arr);
void			*vect_pop_i(t_vect *restrict arr, size_t i);
void			*vect_pop_p(t_vect *restrict arr, void *item);

void			*vect_find_back(t_vect *restrict arr, void *data,
							int (*cmp)(const void *, const void *));
void			*vect_find_front(t_vect *restrict arr, void *data,
							int (*cmp)(const void *, const void *));

void			vect_sort(t_vect *restrict arr,
							int (*cmp)(const void *, const void *),
							void (*sort)(void *, size_t, size_t,
							int (*cmp)(const void *, const void *)));

size_t			vect_flfind_i(t_vect *arr, void *data,
							int (*cmp)(const void *, const void *));
size_t			vect_insert_uniq(t_vect *arr, void *data,
							int (*cmp)(const void *, const void *));

#endif
