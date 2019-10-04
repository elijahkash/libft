/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:51:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/04 17:51:02 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <prf_double.h>

int				ft_nbrlen(long int a)
{
	char tmp[20];

	tmp[0] = '\0';
	ft_strcatnbr(tmp, a);
	return (ft_strlen(tmp));
}
