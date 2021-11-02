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

#include "ft_diff_utils.h"

void			*ft_memrev(void *mem, size_t size)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = ((char *)mem)[i];
		((char *)mem)[i] = ((char *)mem)[j];
		((char *)mem)[j] = tmp;
		i++;
		j--;
	}
	return (mem);
}
