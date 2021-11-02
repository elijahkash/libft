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

inline void	*ft_memset(void *b, int c, size_t len)
{
	return (memset(b, c, len));
}

#else

void		*ft_memset(void *b, int c, size_t len)
{
	while (len)
		((char *)b)[--len] = (unsigned int)c;
	return (b);
}

#endif
