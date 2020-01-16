/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:03:06 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:29 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

void			ft_swap(void *p1, void *p2, size_t size)
{
	char tmp[size];

	ft_memcpy(tmp, p1, size);
	ft_memcpy(p1, p2, size);
	ft_memcpy(p2, tmp, size);
}
