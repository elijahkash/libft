/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:32:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/07 16:40:48 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size <= lendst + 1)
		return (size + lensrc);
	ft_memcpy((void *)&dst[lendst], (void *)src,
				(size - lendst - 1 > lensrc) ? lensrc : size - lendst - 1);
	dst[(size - lendst - 1 > lensrc) ? size - 1 : lendst + lensrc] = '\0';
	return (lendst + lensrc);
}
