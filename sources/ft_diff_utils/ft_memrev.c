/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:05:20 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/11 14:08:30 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

void			*ft_memrev(void *mem, size_t size)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = ((char *)mem)[i];
		((char *)mem)[i] = ((char *)mem)[j];
		((char *)mem)[j] = tmp;
		i++;
		j--;
	}
	return (mem);
}
