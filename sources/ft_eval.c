/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:58:15 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:15 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_eval.h>

#include <ft_libc.h>

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
