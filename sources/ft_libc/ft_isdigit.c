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

#include "ft_libc.h"

#ifdef USE_LIBC

# include <ctype.h>

inline int	ft_isdigit(int c)
{
	return (isdigit(c));
}

#else

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

#endif
