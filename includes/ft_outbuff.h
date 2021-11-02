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

#ifndef FT_OUTBUFF_H
# define FT_OUTBUFF_H

# include <string.h>

# define FT_OUTBUFF_SIZE 8196

typedef struct	s_outbuff
{
	char	buff[FT_OUTBUFF_SIZE];
	size_t	curlen;
	int		fd;
}				t_outbuff;

/*
**	ft_outbuff_base.c
*/
void			ft_force_buff(void);
void			ft_force_outbuff(t_outbuff *buff);
void			ft_force_buff_fd(int fd);
t_outbuff		*ft_get_outbuff_item(int fd);

/*
**	ft_outbuff_add.c
*/
int				ft_buf_add(int fd, const char *str, size_t len);
int				ft_buff_add_to_outbuff(t_outbuff *restrict buff,
										const char *str, size_t len);

#endif
