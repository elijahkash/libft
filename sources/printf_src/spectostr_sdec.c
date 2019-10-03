/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_sdec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:32:16 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 00:12:20 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

char	*spectostr_sdec(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	tmp[130];
	int		len;
	int		zero_count;
	int		sign;

	ft_getsnbr_base(get_dec_item_by_size(argptr, spec.sizes), DEC_BASE, tmp);
	len = ft_strlen(tmp);
	if (len == 1 && *tmp == '0' && spec.precision == 0)
		return (ft_zerostr());
	if (spec.precision > len - (sign = ((*tmp == '-') ? 1 : 0)))
		output = (char *)malloc(spec.precision + 60 + sign);
	else
		output = (char *)malloc(len + 60);
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
//		return (NULL + (errno = ENOMEM) * 0);
	ft_memcpy(output, tmp, len + 1);
	zero_count = spec.precision - len + sign;
	if (spec.precision != NOT_DETERM && zero_count > 0)
	{
		ft_memmove(output + sign + zero_count, output + sign, len - sign + 1);
		ft_strset(output + sign, '0', zero_count);
	}
	return (output);
}
