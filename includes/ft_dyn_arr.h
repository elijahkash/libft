/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:07:56 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:45 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYN_ARR_H
# define FT_DYN_ARR_H

# include <string.h>

typedef struct	s_darr
{
	void	**arr;
	size_t	*item_size;
	size_t	*curlen;
	size_t	*max_len;
}				t_darr;

void			darr_init(t_darr *arr, size_t item_size, size_t init_len);
void			darr_del(t_darr *arr);

void			*darr(t_darr arr, size_t i);
size_t			darr_i(t_darr arr, void *item);
size_t			darr_l(t_darr arr);
void			*darr_eq(t_darr arr, size_t i, void *data);
void			*darr_add(t_darr arr, void *data);
void			*darr_add_i(t_darr arr, void *data, size_t i);
void			*darr_pop(t_darr arr);
void			*darr_pop_i(t_darr arr, size_t i);
void			*darr_pop_p(t_darr arr, void *item);
void			*darr_find(t_darr arr, void *data);
void			darr_sort(t_darr arr, int(*cmp)(const void *, const void *),
							void (*sort)(void *, size_t, size_t,
									int (*cmp)(const void *, const void *)));

void			*darr_add_str(t_darr arr, void *data);
void			darr_extend(t_darr arr, size_t n);

size_t			darr_setl(t_darr arr, size_t newlen);
void			*darr_clean(t_darr arr);
void			*darr_top(t_darr arr);
void			*darr_(t_darr arr, int i);

size_t			darr_flfind_i(t_darr arr, void *data,
								int (*cmp)(const void *, const void *));

size_t			darr_insert_uniq(t_darr arr, void *data,
								int (*cmp)(const void *, const void *));
void			darr_trim(t_darr arr);
void			*darr_add_n(t_darr arr, void *data, size_t n);
/*
** void			*darr_cut(t_darr arr, size_t i);
*/

#endif
