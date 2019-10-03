/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:03:06 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 21:07:52 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_swap(void *p1, void *p2, size_t size)
{
	char tmp[size];

	ft_memcpy(tmp, p1, size);
	ft_memcpy(p1, p2, size);
	ft_memcpy(p2, tmp, size);
}
