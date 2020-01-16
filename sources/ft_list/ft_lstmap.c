/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:23:37 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:13 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*nlist;
	t_list		*nitem;
	t_list		*last;

	nlist = NULL;
	while (lst)
	{
		nitem = f(lst);
		if (!nlist)
		{
			nlist = nitem;
			last = nitem;
		}
		else
		{
			last->next = nitem;
			last = nitem;
		}
		lst = lst->next;
	}
	return (nlist);
}
