/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:24:55 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:26 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_memory_manager.h>

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == __SIZE_MAX__)
		return (NULL);
	str = (char *)ft_memalloc(size + 1);
	return (str);
}
