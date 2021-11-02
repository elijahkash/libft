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

#ifndef FT_FAST_INPUT_GNL_H
# define FT_FAST_INPUT_GNL_H

# define FAST_INPUT_GNL_BUFF_SIZE 8192

typedef struct		s_buff_info
{
	char			*start;
	int				len;
}					t_buff_info;

int					ft_fast_input_gnl(char **line);

#endif
