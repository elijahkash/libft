/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:08:29 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 21:09:06 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
