/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:59:39 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:37:36 by mtrisha          ###   ########.fr       */
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
