/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alst_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:32:14 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/23 19:13:19 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list_on_arr.h>

#include <libft.h>

void			alst_init(t_alst *restrict self, size_t item_size,
												size_t init_len)
{
	size_t	free_mem_mask_size;

	self->item_size = item_size;
	self->curlen = 0;
	self->max_size = init_len;
	self->head = ALST_SPEC_VALUE;
	self->tail = ALST_SPEC_VALUE;
	free_mem_mask_size = (init_len / 64 + ((init_len % 64) ? 1 : 0)) *
							sizeof(__uint64_t);
	self->mem = ft_malloc((item_size + sizeof(t_alst_item)) * init_len +
							free_mem_mask_size);
	self->free_space_mask = self->mem;
	self->items = self->mem + free_mem_mask_size;
	self->list = self->mem + free_mem_mask_size + init_len * item_size;
	ft_memset(self->free_space_mask, -1, free_mem_mask_size);
}

void			alst_del(t_alst *restrict self)
{
	if (self->mem)
		ft_free(self->mem);
	ft_bzero(self, sizeof(t_alst));
}

void			alst_extend(t_alst *restrict self)
{
	void	*tmp;
	size_t	old_size;
	size_t	new_free_mem_mask_size;
	size_t	old_free_mem_mask_size;

	old_size = self->max_size;
	self->max_size *= 2;
	new_free_mem_mask_size = (self->max_size / 64 + ((self->max_size % 64)
								? 1 : 0)) * sizeof(__uint64_t);
	old_free_mem_mask_size = (old_size / 64 + ((old_size % 64) ? 1 : 0)) *
								sizeof(__uint64_t);
	tmp = ft_malloc((self->item_size + sizeof(t_alst_item)) * self->max_size +
						new_free_mem_mask_size);
	ft_memset(tmp, -1, new_free_mem_mask_size);
	self->free_space_mask = ft_memcpy(tmp, self->mem, old_free_mem_mask_size);
	self->items = ft_memcpy(tmp + new_free_mem_mask_size, self->items,
							old_size * self->item_size);
	self->list = ft_memcpy(tmp + new_free_mem_mask_size + self->max_size *
				self->item_size, self->list, old_size * sizeof(t_alst_item));
	ft_free(self->mem);
	self->mem = tmp;
}

size_t			alst_get_space(t_alst *restrict self)
{
	size_t		res;
	__uint64_t	tmp;

	res = (size_t)-1;
	if (self->curlen == self->max_size)
		alst_extend(self);
	while (self->free_space_mask[++res] == 0)
		continue ;
	tmp = self->free_space_mask[res];
	asm("bsfq\t%0, %0" : "+rm" (tmp));
	self->free_space_mask[res] &= ~(1llu << tmp);
	return (res * 64 + tmp);
}
