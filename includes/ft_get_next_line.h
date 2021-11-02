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
