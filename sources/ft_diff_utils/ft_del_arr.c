/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:20:54 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:54 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_memory_manager.h>

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
