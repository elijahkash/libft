/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:30:44 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 13:39:22 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_outbuff.h>

#include <libft.h>

int			ft_buff_add_to_outbuff(t_outbuff *restrict buff,
										const char *str, int len)
{
	const char	*ptr;
	int			tmp;

	ptr = str;
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

int			ft_buf_add(int fd, const char *str, int len)
{
	t_outbuff	*buff;

	buff = ft_get_outbuff_item(fd);
	ft_buff_add_to_outbuff(buff, str, len);
	return (1);
}
