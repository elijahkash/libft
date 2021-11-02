/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_outbuff.h"

#include "libft.h"

int			ft_buff_add_to_outbuff(t_outbuff *restrict buff,
										const char *str, size_t len)
{
	const char	*ptr;
	int			tmp;

	ptr = str;
	while (len + buff->curlen >= FT_OUTBUFF_SIZE)
	{
		tmp = (FT_OUTBUFF_SIZE - buff->curlen);
		ft_memcpy(buff->buff + buff->curlen, ptr, tmp);
		len -= tmp;
		ptr += tmp;
		buff->curlen = FT_OUTBUFF_SIZE;
		ft_force_outbuff(buff);
	}
	ft_memcpy(buff->buff + buff->curlen, ptr, len);
	buff->curlen += len;
	return (1);
}

int			ft_buf_add(int fd, const char *str, size_t len)
{
	t_outbuff	*buff;

	buff = ft_get_outbuff_item(fd);
	ft_buff_add_to_outbuff(buff, str, len);
	return (1);
}
