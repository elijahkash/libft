/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_auxfunc1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:00:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/26 20:42:39 by mtrisha          ###   ########.fr       */
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
