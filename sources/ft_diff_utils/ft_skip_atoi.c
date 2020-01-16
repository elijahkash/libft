/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:59:39 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:17 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

char			*ft_skip_atoi(char *s)
{
	while (ft_isws(*s))
		s++;
	if (*s == '-' || *s == '+')
		s++;
	s = (char *)ft_skip_digits(s);
	return (s);
}
