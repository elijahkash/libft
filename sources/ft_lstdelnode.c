/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:48 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/10 17:48:58 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

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
		free(iter);
		*node = NULL;
	}
	else
		while (next)
		{
			if (next == *node)
			{
				del(next->content, iter->content_size);
				iter->next = next->next;
				free(next);
				*node = NULL;
			}
			iter = next;
			next = next->next;
		}
	return ;
}
