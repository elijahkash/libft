/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_auxfunc1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:00:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:48 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_double.h>

#include <libft.h>

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
