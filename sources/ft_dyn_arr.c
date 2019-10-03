/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:22:03 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 22:53:17 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

#include <libft.h>

void	darr_init(t_darr *arr, size_t item_size, size_t init_len)
{
	if (!item_size && !init_len)
	{
		write(FD_STDERR, DARRINIT_ERR_MSG, DARRINIT_ERR_MSG_LEN);
		ft_gb_clean();
		exit(0);
	}
	arr->item_size = item_size;
	arr->curlen = 0;
	arr->max_len = init_len;
	arr->arr = ft_malloc(init_len * item_size);
}

void	darr_del(t_darr *arr)
{
	ft_free(&arr->arr);
	ft_bzero(arr, sizeof(t_darr));
}

void	*darr(t_darr arr, size_t i)
{
	return(NULL); //TODO: а нужна ли это функция?
}
