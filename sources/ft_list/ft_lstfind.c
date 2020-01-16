/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:05 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:13 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

t_list	*ft_lstfind(t_list *head, void *search_d,
					int (*f)(void *, void *))
{
	while (head)
	{
		if (f(head->content, search_d))
			return (head);
		head = head->next;
	}
	return (head);
}
