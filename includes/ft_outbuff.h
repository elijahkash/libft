/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:54 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/12 14:33:20 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTBUFF_H
# define FT_OUTBUFF_H

# define PRF_BUFF_SIZE 8196

typedef struct	s_outbuff
{
	char	buff[PRF_BUFF_SIZE];
	int		curlen;
	int		fd;
}				t_outbuff;

void			ft_force_buff(void);
t_outbuff		*ft_get_outbuff_item(int fd);

int				ft_is_equalfd_in_toutbuf(void *item1, void *item2);
void			ft_force_outbuff(t_outbuff *buff);
void			ft_force_buff_fd(int fd);
int				ft_buff_add_to_outbuff(t_outbuff *restrict buff,
										const char *str, int len);
int				ft_buf_add(int fd, const char *str, int len);

#endif
