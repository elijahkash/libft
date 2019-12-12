/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:30:44 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/12 15:06:54 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff.h>

#include <libft.h>

#include <unistd.h>

int		ft_is_equalfd_in_toutbuf(void *item1, void *item2)
{
	if (((t_outbuff *)item1)->fd == *(int *)item2)
		return (1);
	return (0);
}

void		ft_force_outbuff(t_outbuff *buff)
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

void			ft_force_buff_fd(int fd)
{
	t_outbuff	*buff;

	buff = ft_get_outbuff_item(fd);
	ft_force_outbuff(buff);
}

int				ft_buff_add_to_outbuff(t_outbuff *restrict buff,
										const char *str, int len)
{
	const char	*ptr;
	int			tmp;

	ptr = str;
	//write(1, str, len);
	while (len + buff->curlen >= PRF_BUFF_SIZE)
	{
		tmp = (PRF_BUFF_SIZE - buff->curlen);
		ft_memcpy(buff->buff + buff->curlen, ptr, tmp);
		len -= tmp;
		ptr += tmp;
		buff->curlen = PRF_BUFF_SIZE;
		ft_force_outbuff(buff);
	}
	ft_memcpy(buff->buff + buff->curlen, ptr, len);
	buff->curlen += len;
	return (1);
}

int				ft_buf_add(int fd, const char *str, int len)
{
	t_outbuff	*buff;

	buff = ft_get_outbuff_item(fd);
	ft_buff_add_to_outbuff(buff, str, len);
	return (1);
}
