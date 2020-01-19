/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:54 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 15:01:42 by Kashnitskiy      ###   ########.fr       */
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
