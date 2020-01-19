/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:42 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 14:25:49 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff.h>

#include <libft.h>

#include <unistd.h>

static t_list	*g_buff = NULL;

static inline int	ft_is_equalfd_in_toutbuf(void *restrict item1,
											void *restrict item2)
{
	return ((((t_outbuff *)item1)->fd == *(int *)item2) ? 1 : 0);
}

t_outbuff			*ft_get_outbuff_item(int fd)
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

void				ft_force_buff(void)
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

void				ft_force_outbuff(t_outbuff *restrict buff)
{
	size_t		len;

	if (!ft_get_g_outstr())
		write(buff->fd, buff->buff, buff->curlen);
	else
	{
		len = ft_strlen(ft_get_g_outstr());
		ft_memmove(ft_get_g_outstr() + len, buff->buff, buff->curlen);
		ft_get_g_outstr()[len + buff->curlen] = '\0';
	}
	buff->curlen = 0;
}

void				ft_force_buff_fd(int fd)
{
	t_outbuff	*buff;

	buff = ft_get_outbuff_item(fd);
	ft_force_outbuff(buff);
}
