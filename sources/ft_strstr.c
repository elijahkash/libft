/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:14:22 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/06 20:09:05 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			check = 1;
			while (needle[++j] != 0)
			{
				check = (needle[j] == haystack[i + j]) ? 1 : 0;
				if (!check)
					break ;
			}
			if (check)
				return ((char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}
