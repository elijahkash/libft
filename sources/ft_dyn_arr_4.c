/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:33:55 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/09 15:40:14 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dyn_arr.h>

#include <libft.h>

void		*darr_add_str(t_darr arr, void *data)
{
	void	*newstr;

	if (*arr.curlen == *arr.max_len)
		darr_extend(arr);
	newstr = ft_malloc(ft_strlen(data));
	ft_strcpy(newstr, data);
	ft_memcpy(darr(arr, *arr.curlen), &newstr, *arr.item_size);
	(*arr.curlen)++;
	return (darr(arr, *arr.curlen - 1));
}
