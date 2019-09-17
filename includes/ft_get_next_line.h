/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:51:41 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/17 21:40:16 by mtrisha          ###   ########.fr       */
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
