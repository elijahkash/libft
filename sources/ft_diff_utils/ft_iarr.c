/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:07:58 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:57 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_memory_manager.h>

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
