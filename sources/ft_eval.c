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

#include "ft_eval.h"

#include "ft_libc.h"

static char	g_eval_mem[8];

inline void		*ft_i(int i)
{
	return (ft_memcpy(g_eval_mem, &i, sizeof(int)));
}

inline void		*ft_z(size_t i)
{
	return (ft_memcpy(g_eval_mem, &i, sizeof(size_t)));
}

inline void		*ft_lli(long long int i)
{
	return (ft_memcpy(g_eval_mem, &i, sizeof(long long int)));
}

inline void		*ft_c(char i)
{
	return (ft_memcpy(g_eval_mem, &i, sizeof(char)));
}

inline void		*ft_p(void *p)
{
	return (ft_memcpy(g_eval_mem, &p, sizeof(void *)));
}
