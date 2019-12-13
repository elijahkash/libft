/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:05 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:53:02 by mtrisha          ###   ########.fr       */
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
