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

#include "ft_sort.h"

#include "ft_libft_mod.h"

#include "libft.h"

#ifdef USE_LIBC

# include <stdlib.h>

inline void	ft_qsort(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *))
{
	qsort(base, nel, width, cmp);
}

#else

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

#endif

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
