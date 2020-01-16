/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:21:10 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:56 by Kashnitskiy      ###   ########.fr       */
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
