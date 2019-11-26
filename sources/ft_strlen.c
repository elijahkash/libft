/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:21:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 16:58:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

#ifdef USE_LIBC

inline size_t	ft_strlen(const char *str)
{
	return (strlen(str));
}

#else

size_t			ft_strlen(const char *str)
{
	size_t res;

	res = 0;
	while (str[res] != '\0')
		++res;
	return (res);
}

#endif
