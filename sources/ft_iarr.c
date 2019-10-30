/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:07:58 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/30 21:08:18 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
