/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:51:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/26 20:44:42 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

#include <libft.h>

int				ft_nbrlen(long int a)
{
	char tmp[20];

	tmp[0] = '\0';
	ft_strcatnbr(tmp, a);
	return (ft_strlen(tmp));
}
