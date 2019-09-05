/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:43:49 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/05 16:50:36 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t tmp;

	tmp = (n > ft_strlen(s2) + 1) ? ft_strlen(s2) : n - 1;
	ft_memcpy(s1 + ft_strlen(s1), s2, tmp);
	*(s1 + ft_strlen(s1) + tmp) = '\0';
	return (s1);
}
