/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:51:41 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:41 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFF_SIZE_GNL
#  define BUFF_SIZE_GNL 512
# endif

# if BUFF_SIZE_GNL  <= 0
#  error wrong BUFF_SIZE
# endif

typedef struct	s_fdbuff
{
	int			fd;
	char		content[BUFF_SIZE_GNL + 1];
}				t_fdbuff;

int				ft_get_next_line(const int fd, char **line);

#endif
