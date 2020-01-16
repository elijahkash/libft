/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:08:29 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:10 by Kashnitskiy      ###   ########.fr       */
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
