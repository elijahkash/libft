/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:53:55 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/05 19:10:58 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	const char *i;

	i = s;
	while (*i)
	{
		if (*i == (char)c)
			return ((char *)i);
		i++;
	}
	return (NULL);
}
