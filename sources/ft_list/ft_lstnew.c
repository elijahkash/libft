/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:54:01 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:47:58 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

#include <ft_memory_manager.h>
#include <ft_libc.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	nlist = (t_list *)ft_malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	nlist->next = NULL;
	if (!content)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		if (!(nlist->content = ft_malloc(content_size)))
		{
			ft_free(nlist);
			return (NULL);
		}
		ft_memcpy(nlist->content, content, content_size);
		nlist->content_size = content_size;
	}
	return (nlist);
}
