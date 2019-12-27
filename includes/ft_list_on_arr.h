/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_on_arr.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:31:03 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/27 15:58:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_ON_ARR_H
# define FT_LIST_ON_ARR_H

# include <string.h>

//TODO: restrict inline

typedef struct	s_alst_item
{
	size_t	self;
	size_t	next;
}				t_alst_item;

typedef struct	s_list_on_arr
{
	void		*mem;
	__uint64_t	*free_space_mask;
	void		*items;
	t_alst_item	*list;
	size_t		head;
	size_t		tail;
	size_t		curlen;
	size_t		item_size;
	size_t		max_size;
}				t_alst;

# define 		ALST_SPEC_VALUE ((size_t)(0 - 1))

void			alst_init(t_alst *self, size_t item_size,
										size_t init_len);
void			alst_del(t_alst *self);
void			alst_extend(t_alst *self);

size_t			alst_get_space(t_alst *self);

t_alst_item		*alst_add_head(t_alst *self, void *data);
t_alst_item		*alst_add_tail(t_alst *self, void *data);
t_alst_item		*alst_add_after(t_alst *self, t_alst_item *item, void *data);

void			*alst_pop_head(t_alst *self);

#endif
