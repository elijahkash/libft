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

void	ft_del_arr(void ***arr, size_t item_size)
{
	int		i;

	i = 0;
	while (((char **)(*arr))[i * item_size])
	{
		ft_free(((char **)(*arr))[i * item_size]);
		((char **)(*arr))[i++ * item_size] = NULL;
	}
	ft_free((*arr));
	*arr = NULL;
}
