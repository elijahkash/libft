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

#include "ft_list.h"

#include "ft_memory_manager.h"

void	ft_lstdelnode(t_list **alst, t_list **node,
						void (*del)(void*, size_t))
{
	t_list *iter;
	t_list *next;

	iter = *alst;
	next = iter->next;
	if (iter == *node)
	{
		*alst = iter->next;
		del(iter->content, iter->content_size);
		ft_free(iter);
		*node = NULL;
	}
	else
		while (next)
		{
			if (next == *node)
			{
				del(next->content, next->content_size);
				iter->next = next->next;
				ft_free(next);
				*node = NULL;
			}
			iter = next;
			next = next->next;
		}
}
