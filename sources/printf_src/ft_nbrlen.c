/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:51:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:58:05 by Kashnitskiy      ###   ########.fr       */
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
