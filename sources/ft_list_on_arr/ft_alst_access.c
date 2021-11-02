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

#include "ft_list_on_arr.h"

#include "libft.h"

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
