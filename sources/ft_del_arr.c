/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:20:54 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/19 16:31:03 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

void	ft_del_arr(void ***arr, size_t item_size)
{
	int		i;

	i = 0;
	while (((char **)(*arr))[i * item_size])
	{
		free(((char **)(*arr))[i * item_size]);
		((char **)(*arr))[i++ * item_size] = NULL;
	}
	free((*arr));
	*arr = NULL;
}
