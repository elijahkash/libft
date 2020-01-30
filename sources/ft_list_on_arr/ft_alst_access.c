/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alst_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:23:37 by Kashnitskiy       #+#    #+#             */
/*   Updated: 2020/01/22 18:24:59 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list_on_arr.h>

#include <libft.h>

inline void		*alst(t_alst *restrict self, size_t item)
{
	return (self->items + item * self->item_size);
}

void			*alst_head(t_alst *restrict self)
{
	return (self->items + self->head * self->item_size);
}

void			*alst_tail(t_alst *restrict self)
{
	return (self->items + self->tail * self->item_size);
}
