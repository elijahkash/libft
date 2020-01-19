/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:54 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 14:23:25 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTBUFF_H
# define FT_OUTBUFF_H

# define FT_OUTBUFF_SIZE 8196

typedef struct	s_outbuff
{
	char	buff[FT_OUTBUFF_SIZE];
	int		curlen;
	int		fd;
}				t_outbuff;

/*
**	ft_outbuff_base.c
*/
t_outbuff		*ft_get_outbuff_item(int fd);
void			ft_force_buff(void);
void			ft_force_outbuff(t_outbuff *buff);
void			ft_force_buff_fd(int fd);

/*
**	ft_outbuff_add.c
*/
int				ft_buff_add_to_outbuff(t_outbuff *restrict buff,
										const char *str, int len);
int				ft_buf_add(int fd, const char *str, int len);

#endif
