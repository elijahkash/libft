/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:48 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:53:09 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

#include <ft_memory_manager.h>

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
