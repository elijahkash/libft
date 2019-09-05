/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:32:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/05 21:02:19 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size <= lendst + 1)
		return (size + lensrc);
	ft_memcpy((void *)&dst[lendst], (void *)src, size - lendst - 1);
	dst[size - 1] = '\0';
	return (lendst + lensrc);
}
