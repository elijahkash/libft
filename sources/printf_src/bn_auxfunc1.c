/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_auxfunc1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:00:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 15:00:04 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <prf_double.h>

int				is_last_five(t_bignum res, int start_check)
{
	int		i;

	i = 0;
	while (--start_check > 0)
	{
		if (ft_get_inpos_bignum(res, start_check) != 0)
			return (0);
	}
	return (1);
}
