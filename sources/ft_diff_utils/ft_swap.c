/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:03:06 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/23 18:37:05 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

void			ft_swap(void *p1, void *p2, size_t size)
{
	size_t	i;
	char	tmp;

	i = -1;
	while (++i < size)
	{
		tmp = ((char *)p1)[i];
		((char *)p1)[i] = ((char *)p2)[i];
		((char *)p2)[i] = tmp;
	}
}
