/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:05:49 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 14:25:09 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sort.h>

#include <libft.h>

void	ft_qsort(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *))
{
	size_t	left;
	size_t	right;
	char	mid[width];

	if (nel == 0 || !(right = nel - 1))
		return ;
	ft_memcpy(mid, &(((char *)base)[(nel / 2) * width]), width + (left = 0));
	while (left <= right)
	{
		while (cmp(&(((char *)base)[left * width]), mid) < 0)
			left++;
		while (cmp(&(((char *)base)[right * width]), mid) > 0)
			right--;
		if (left <= right)
			ft_swap(&(((char *)base)[left++ * width]),
					&(((char *)base)[right-- * width]), width);
	}
	if (right > 0)
		ft_qsort(base, right + 1, width, cmp);
	if (left < nel)
		ft_qsort(&(((char *)base)[left * width]), nel - left, width, cmp);
}

void	ft_bublsort(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;

	i = 0;
	j = nel;
	if (!nel)
		return ;
	while (i < j - 1)
	{
		if (cmp(&(((char *)base)[i * width]),
				&(((char *)base)[(i + 1) * width])) > 0)
			ft_swap(&(((char *)base)[i * width]),
					&(((char *)base)[(i + 1) * width]), width);
		if (++i == j - 1)
		{
			i = 0;
			j--;
		}
	}
}