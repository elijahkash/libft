/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_on_arr_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:32:14 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/27 15:58:28 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list_on_arr.h>

#include <libft.h>

void			alst_init(t_alst *self, size_t item_size, size_t init_len)
{
	size_t	free_mem_mask_size;

	self->item_size = item_size;
	self->curlen = 0;
	self->max_size = init_len;
	self->head = ALST_SPEC_VALUE;
	self->tail = ALST_SPEC_VALUE;
	free_mem_mask_size = (init_len / 64 + 1) * sizeof(__uint64_t);
	self->mem = ft_malloc((item_size + sizeof(t_alst_item)) * init_len +
							free_mem_mask_size);
	self->free_space_mask = self->mem;
	self->items = self->mem + free_mem_mask_size;
	self->list = self->mem + free_mem_mask_size + init_len * item_size;
	ft_memset(self->free_space_mask, -1, free_mem_mask_size);
}

void			alst_del(t_alst *self)
{
	if (self->mem)
		ft_free(self->mem);
	ft_bzero(self, sizeof(t_alst));
}

void			alst_extend(t_alst *self)
{
	void	*tmp;
	size_t	old_size;
	size_t	new_free_mem_mask_size;
	size_t	old_free_mem_mask_size;

	old_size = self->max_size;
	self->max_size <<= 1;
	new_free_mem_mask_size = (self->max_size / 64 + 1) * sizeof(__uint64_t);
	old_free_mem_mask_size = (old_size / 64 + 1) * sizeof(__uint64_t);
	tmp = ft_malloc((self->item_size + sizeof(t_alst_item)) * self->max_size +
						new_free_mem_mask_size);
	ft_memset(self->free_space_mask, -1, new_free_mem_mask_size);
	self->free_space_mask = ft_memcpy(tmp, self->mem, old_free_mem_mask_size);
	self->items = ft_memcpy(tmp + new_free_mem_mask_size, self->items,
							old_size * self->item_size);
	self->list = ft_memcpy(tmp + new_free_mem_mask_size + self->max_size *
				self->item_size, self->list, old_size * sizeof(t_alst_item));
	ft_free(self->mem);
	self->mem = tmp;
}

size_t			alst_get_space(t_alst *self)
{
	size_t		res;
	__uint64_t	tmp;

	res = 0;
	if (self->curlen == self->max_size)
		alst_extend(self);
	while (self->free_space_mask[res] == 0)
		res++;
	tmp = self->free_space_mask[res];
	BSR_ASM(tmp);
	self->free_space_mask[res] |= (1 << tmp);
	return (res * 64 + tmp);
}

t_alst_item		*alst_add_head(t_alst *self, void *data)
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

t_alst_item		*alst_add_tail(t_alst *self, void *data)
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

t_alst_item		*alst_add_after(t_alst *self, t_alst_item *item, void *data)
{
	size_t	item_place;

	if (self->curlen == 0)
		return (alst_add_head(self, data));
	item_place = alst_get_space(self);
	ft_memmove(self->items + self->item_size * item_place, data,
				self->item_size);
	self->list[item_place].self = item_place;
	self->list[item_place].next = item->next;
	item->next = item_place;
	self->curlen++;
	return (self->list + item_place);
}

void			*alst_pop_head(t_alst *self)
{
	size_t	item_place;

	if (self->curlen == 0)
		return (NULL);
	item_place = self->head;
	self->head = self->list[self->head].next;
	self->curlen--;
	return (self->items + item_place * self->item_size);
}
