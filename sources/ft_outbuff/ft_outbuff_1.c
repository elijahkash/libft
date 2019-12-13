/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/12 15:11:19 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff.h>

#include <libft.h>

static t_list	*g_buff = NULL;

void			ft_force_buff(void)
{
	t_list		*tmp;

	while (g_buff)
	{
		tmp = g_buff->next;
		ft_force_outbuff(g_buff->content);
		ft_lstdelone(&g_buff, ft_sfree);
		g_buff = tmp;
	}
}

t_outbuff		*ft_get_outbuff_item(int fd)
{
	t_list		*item;

	if ((item = ft_lstfind(g_buff, &fd, ft_is_equalfd_in_toutbuf)))
		return (item->content);
	item = ft_lstnew(NULL, 0);
	item->content = ft_malloc(sizeof(t_outbuff));
	((t_outbuff *)item->content)->fd = fd;
	((t_outbuff *)item->content)->curlen = 0;
	item->content_size = sizeof(t_outbuff);
	ft_lstadd(&g_buff, item);
	return (item->content);
}
