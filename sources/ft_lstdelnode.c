/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:48 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 21:09:09 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
