/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:21:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 12:32:54 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#ifdef TURBO_MOD

size_t	ft_strlen(const char *str)
{
	return (strlen(str));
}

#else

size_t	ft_strlen(const char *str)
{
	size_t res;

	res = 0;
	while (str[res] != '\0')
		++res;
	return (res);
}

#endif
