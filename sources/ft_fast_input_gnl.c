/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_input_gnl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:51:11 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:16 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fast_input_gnl.h>

#include <libft.h>

#include <unistd.h>

int			new_read(char **line, int len,
						char buff[FAST_INPUT_GNL_BUFF_SIZE], t_buff_info *info)
{
	int		ret;
	char	*tmp;

	while ((ret = read(FD_STDIN, buff, FAST_INPUT_GNL_BUFF_SIZE)))
	{
		if (ret < 0 || ret + len >= __INT32_MAX__)
		{
			ft_memdel((void **)line);
			return (-1);
		}
		buff[ret] = '\0';
		if ((tmp = ft_strchr(buff, '\n')))
			break ;
		*line = ft_remalloc(*line, len, len + ret + 1);
		len += ret + ((int)(ft_memcpy(*line + len, buff, ret + 1)) & 0);
	}
	if (ret == 0 && *line == NULL && (*line = ft_malloc(1)))
		return ((line[0][0] = '\0'));
	if (ret == 0)
		return (1);
	*line = ft_remalloc(*line, len, len + (tmp - buff) + 1);
	ft_memcpy(*line + len, buff, tmp - buff);
	len += ((info->start = tmp + 1) - 1 - buff);
	(*line)[len] = '\0';
	return (((info->len = ret - (tmp - buff) - 1) & 0) + 1);
}

int			ft_fast_input_gnl(char **line)
{
	static char			buff[FAST_INPUT_GNL_BUFF_SIZE + 1];
	static t_buff_info	info = {NULL, 0};
	char				*tmp;
	int					len;

	*line = NULL;
	if (info.len == 0)
		return (new_read(line, 0, buff, &info));
	if ((tmp = ft_strchr(info.start, '\n')))
	{
		len = tmp - info.start;
		*line = ft_memcpy(ft_malloc(len + 1), info.start, len);
		(*line)[len] = '\0';
		info.start = tmp + 1;
		info.len -= (len + 1);
		return (1);
	}
	else
	{
		len = info.len;
		*line = ft_memcpy(ft_malloc(len + 1), info.start, len + 1);
		info.start = NULL;
		info.len = 0;
		return (new_read(line, len, buff, &info));
	}
}
