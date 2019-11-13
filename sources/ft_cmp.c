/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:46:52 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/13 12:52:27 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
