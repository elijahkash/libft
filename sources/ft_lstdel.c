/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:08:29 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:52:23 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

#include <ft_memory_manager.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *head;

	head = *alst;
	while (head)
	{
		del(head->content, head->content_size);
		next = head->next;
		ft_free(head);
		head = next;
	}
	*alst = NULL;
}
