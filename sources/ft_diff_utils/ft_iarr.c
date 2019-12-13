/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:07:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:37:54 by mtrisha          ###   ########.fr       */
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
