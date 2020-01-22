/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alst_addpop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:32:14 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/22 18:23:36 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list_on_arr.h>

#include <libft.h>

t_alst_item		*alst_add_head(t_alst *restrict self, void *restrict data)
{
	size_t	item_place;

	item_place = alst_get_space(self);
	ft_memmove(self->items + self->item_size * item_place, data,
				self->item_size);
	self->list[item_place].self = item_place;
	if (self->curlen++ == 0)
		self->tail = item_place;
	self->list[item_place].next = self->head;
	self->head = item_place;
	return (self->list + item_place);
}

t_alst_item		*alst_add_tail(t_alst *restrict self, void *restrict data)
{
	size_t	item_place;

	item_place = alst_get_space(self);
	ft_memmove(self->items + self->item_size * item_place, data,
				self->item_size);
	self->list[item_place].self = item_place;
	self->list[item_place].next = ALST_SPEC_VALUE;
	if (self->curlen++ == 0)
		self->head = item_place;
	else
		self->list[self->tail].next = item_place;
	self->tail = item_place;
	return (self->list + item_place);
}

t_alst_item		*alst_add_after(t_alst *restrict self, size_t item,
								void *restrict data)
{
	size_t			item_place;
	t_alst_item		*tmp;

	if (self->curlen == 0)
		return (alst_add_head(self, data));
	item_place = alst_get_space(self);
	ft_memmove(self->items + self->item_size * item_place, data,
				self->item_size);
	tmp = self->list + item;
	self->list[item_place].self = item_place;
	self->list[item_place].next = tmp->next;
	tmp->next = item_place;
	self->curlen++;
	return (self->list + item_place);
}

void			*alst_pop_head(t_alst *restrict self)
{
	size_t	item_place;

	if (self->curlen == 0)
		return (NULL);
	item_place = self->head;
	self->head = self->list[self->head].next;
	self->free_space_mask[item_place / 64] |= (1llu << item_place % 64);
	(self->curlen)--;
	return (self->items + item_place * self->item_size);
}

void			*alst_pop_after(t_alst *restrict self, size_t item)
{
	size_t	next;

	if (self->curlen == 0)
		return (NULL);
	if (self->curlen == 1)
		return (alst_pop_head(self));
	next = self->list[item].next;
	self->list[item].next = self->list[next].next;
	if (self->tail == next)
		self->tail = item;
	self->free_space_mask[next / 64] |= (1llu << next % 64);
	(self->curlen)--;
	return (self->items + next * self->item_size);
}
