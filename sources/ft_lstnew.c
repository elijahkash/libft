/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:54:01 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/06 12:32:41 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	nlist = (t_list *)malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	nlist->next = NULL;
	if (!content)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	nlist->content = content ? (void *)content : NULL;
	nlist->content_size = content ? content_size : 0;
	return (nlist);
}
