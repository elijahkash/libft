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

#include "ft_memory_manager.h"

void		ft_init_iarr(int ***arr, int row, int col)
{
	int i;

	i = 0;
	*arr = ft_malloc(sizeof(int *) * row);
	while (i < row)
	{
		(*arr)[i] = ft_malloc(col * sizeof(int));
		i++;
	}
}

void		ft_del_iarr(int **arr, int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}
