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
