/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:34:28 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/06 17:03:11 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	if (needle[0] == 0 || len == 0)
		return ((needle[0] == 0) ? (char *)haystack : NULL);
	while (haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			check = 1;
			while (needle[++j] != 0 && i + j <= len)
			{
				check = (needle[j] == haystack[i + j]) ? 1 : 0;
				if (!check)
					break ;
			}
			if (check || i + j > len)
				return ((i + j > len) ? NULL : (char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}
