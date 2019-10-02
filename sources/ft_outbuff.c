/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/01 23:02:10 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff.h>

#include <libft.h>

#include <unistd.h>

static t_list	*g_buff = 0;

void			forse_buff(void)
{
	t_list		*tmp;
	t_outbuff	*buff;

	while (g_buff)
	{
		tmp = g_buff->next;
		buff = ((t_outbuff *)g_buff->content);
		write(buff->fd, buff->buff, buff->curlen);
		ft_lstdelone(&g_buff, ft_free);
		g_buff = tmp;
	}
}

static void		forse_item(t_list *item)
{
	t_outbuff *buff;

	buff = ((t_outbuff *)item->content);
	write(buff->fd, buff->buff, buff->curlen);
	((t_outbuff *)item->content)->curlen = 0;
}

static int		is_equalfd_in_toutbuf(void *item1, void *item2)
{
	if (((t_outbuff *)item1)->fd == *(int *)item2)
		return (1);
	return (0);
}

int				ft_buf_add(int fd, const char *str, int len)
{
	t_list		*item;

	if ((item = ft_lstfind(g_buff, &fd, is_equalfd_in_toutbuf)))
	{
		while (len > 0)
		{
			((t_outbuff *)item->content)->buff
			[(((t_outbuff *)item->content)->curlen)++] = *str++ + (len--) * 0;
			if (((t_outbuff *)item->content)->curlen == PRF_BUFF_SIZE)
				forse_item(item);
		}
		return (1);
	}
	if (!(item = ft_lstnew(NULL, 0)))
		return (0 + (errno = ENOMEM) * 0);
	if (!(item->content = ft_memalloc(sizeof(t_outbuff))))
	{
		ft_lstdelone(&item, ft_free);
		return (0 + (errno = ENOMEM) * 0);
	}
	item->content_size = sizeof(t_outbuff);
	((t_outbuff *)item->content)->fd = fd;
	ft_lstadd(&g_buff, item);
	ft_buf_add(fd, str, len);
	return (1);
}
