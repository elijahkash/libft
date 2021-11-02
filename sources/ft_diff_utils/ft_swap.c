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

#include "ft_libc.h"

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
