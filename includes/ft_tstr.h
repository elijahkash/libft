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

#ifndef FT_TSTR_H
# define FT_TSTR_H

# include <string.h>

typedef struct	s_str
{
	char	*str;
	size_t	len;
}				t_str;

t_str			*ft_tstrdup(t_str s);
size_t			ft_findlwordlf(t_str s, int (*f)(char));
size_t			ft_cfwords(t_str s, int (*f)(char));
t_str			**ft_tstrsplit(t_str s, int (*f)(char));

#endif
