/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_on_arr.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:31:03 by mtrisha           #+#    #+#             */
/*   Updated: 2020/03/17 14:23:14 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_ON_ARR_H
# define FT_LIST_ON_ARR_H

# include <string.h>

# ifdef __linux__
#  include <stdint.h>
# endif

typedef struct	s_alst_item
{
	size_t	self;
	size_t	next;
}				t_alst_item;

typedef struct	s_list_on_arr
{
	void *restrict			mem;
	__uint64_t *restrict	free_space_mask;
	void *restrict			items;
	t_alst_item *restrict	list;
	size_t					head;
	size_t					tail;
	size_t					curlen;
	size_t					item_size;
	size_t					max_size;
}				t_alst;

# define ALST_SPEC_VALUE	__SIZE_MAX__

/*
** ft_list_on_arr_base.c
*/

void			alst_init(t_alst *self, size_t item_size,
										size_t init_len);
void			alst_del(t_alst *self);
void			alst_extend(t_alst *self);
size_t			alst_get_space(t_alst *self);

/*
** ft_list_on_arr_access.c
*/

void			*alst(t_alst *self, size_t item);
void			*alst_head(t_alst *self);
void			*alst_tail(t_alst *self);

/*
** ft_list_on_arr_addpop.c
*/

t_alst_item		*alst_add_head(t_alst *self, void *data);
t_alst_item		*alst_add_tail(t_alst *self, void *data);
t_alst_item		*alst_add_after(t_alst *self, size_t item, void *data);

void			*alst_pop_head(t_alst *self);
void			*alst_pop_after(t_alst *self, size_t item);

/*
** ft_list_on_arr_utils.c
*/

void			alst_map(t_alst *self, void (*func)(void *));

#endif
