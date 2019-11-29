/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:46:52 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/29 17:18:25 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cmp.h>

#include <ft_libc.h>
#include <string.h>

inline int		ft_icmp(const void *p1, const void *p2)
{
	return (*((int *)p1) - *((int *)p2));
}

inline int		ft_ccmp(const void *p1, const void *p2)
{
	return (*((char *)p1) - *((char *)p2));
}

inline int		ft_scmp(const void *p1, const void *p2)
{
	return (ft_strcmp(*((char **)p1), *((char **)p2)));
}

inline int		ft_zcmp(const void *p1, const void *p2)
{
	return (*((size_t *)p1) - *((size_t *)p2));
}

inline int		ft_pcmp(const void *p1, const void *p2)
{
	return (*(void **)p1 - *(void **)p2);
}
