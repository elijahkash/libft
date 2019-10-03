/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:05:49 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 21:08:20 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sort.h>

#include <libft.h>

void	ft_qsort(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *))
{
	size_t	l;
	size_t	r;
	char	mid[width];

	if (nel == 0 || !(r = nel - 1))
		return ;
	ft_memcpy(mid, &(((char *)base)[(nel / 2) * width]), width + (l = 0));
	while (l <= r)
	{
		while (cmp(&(((char *)base)[l * width]), mid) < 0)
			l++;
		while (cmp(&(((char *)base)[r * width]), mid) > 0)
			r--;
		if (l <= r)
			ft_swap(&(((char *)base)[l++ * width]),
					&(((char *)base)[r-- * width]), width);
	}
	if (r > 0)
		ft_qsort(base, r + 1, width, cmp);
	if (l < nel)
		ft_qsort(&(((char *)base)[l * width]), nel - l, width, cmp);
}
