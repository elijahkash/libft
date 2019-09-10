/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:05 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/10 17:46:10 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
