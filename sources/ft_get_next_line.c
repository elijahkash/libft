/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:51:16 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:16 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_get_next_line.h>

#include <libft.h>

#include <unistd.h>

static int		find_fd(void *data, void *search_d)
{
	if (((t_fdbuff *)data)->fd == *((int *)search_d))
		return (1);
	return (0);
}

static int		make_static_buff(char **line, t_list **lst_filebuff,
		const int fd)
{
	t_list		*newnode;
	t_fdbuff	item;
	size_t		len;

	if (ft_strlen(*line) == 0)
		return (0);
	if (!ft_strchr(*line, '\n'))
		return (1);
	item.fd = fd;
	ft_bzero(item.content, BUFF_SIZE_GNL + 1);
	len = &(*line)[ft_strlen(*line)] - ft_strchr(*line, '\n');
	ft_memcpy(item.content, ft_strchr(*line, '\n') + 1, len);
	if (!(newnode = ft_lstnew(&item, sizeof(t_fdbuff))))
		return (-1);
	ft_lstadd(lst_filebuff, newnode);
	ft_bzero(ft_strchr(*line, '\n'), len);
	if (!(*line = ft_remalloc(*line, ft_strlen(*line) + 1,
									ft_strlen(*line) + 1)))
	{
		ft_lstdelnode(lst_filebuff, lst_filebuff, ft_sfree);
		return (-1);
	}
	return (1);
}

static int		read_file(const int fd, char **line, t_list **lst_filebuff)
{
	char		buf[BUFF_SIZE_GNL + 1];
	size_t		len;
	int			ret;

	while ((ret = read(fd, buf, BUFF_SIZE_GNL)))
	{
		if (ret < 0)
		{
			ft_free(*line);
			return (-1);
		}
		buf[ret] = '\0';
		len = ft_strlen(*line);
		if (len + ret + 1 >= __SIZE_MAX__)
		{
			ft_free(*line);
			return (-1);
		}
		if (!(*line = (char *)ft_remalloc(*line, len, len + ret + 1)))
			return (-1);
		ft_memcpy(*line + len, buf, ret + 1);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	return (make_static_buff(line, lst_filebuff, fd));
}

static int		read_buffer(char *ptr, char **line, char *nptr)
{
	size_t len;

	len = nptr - ptr;
	if (!(*line = (char *)ft_remalloc(*line, 1, len + 1)))
		return (-1);
	ft_memcpy(*line, ptr, len);
	(*line)[len] = '\0';
	ft_memmove(ptr, ptr + len + 1, BUFF_SIZE_GNL + 1 - len - 1);
	ft_bzero(ptr + BUFF_SIZE_GNL + 1 - len, len + 1);
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*lst_filebuff = NULL;
	t_list			*node;
	char			*ptr;
	char			*buf;

	if (!line || !(*line = ft_strnew(0)))
		return (-1);
	(*line)[0] = '\0';
	node = ft_lstfind(lst_filebuff, (void *)&fd, &find_fd);
	if (!node)
		return (read_file(fd, line, &lst_filebuff));
	buf = ((t_fdbuff *)(node->content))->content;
	if ((ptr = ft_strchr((buf), '\n')))
		return (read_buffer(buf, line, ptr));
	else
	{
		if (ft_strlen(buf) != 0)
		{
			if (!(*line = (char *)ft_remalloc(*line, 1, 1 + ft_strlen(buf))))
				return (-1);
			ft_memcpy(*line, buf, ft_strlen(buf) + 1);
		}
		ft_lstdelnode(&lst_filebuff, &node, ft_sfree);
		return (read_file(fd, line, &lst_filebuff));
	}
}
