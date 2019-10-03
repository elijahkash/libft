/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_udec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:57:49 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 15:19:57 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <stdlib.h>
#include <prf_get_item_by_size.h>
#include <libft.h>

char	*spectostr_udec(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	tmp[65];
	int		len;
	int		zero_count;

	ft_getunbr_base(get_udec_item_by_size(argptr, spec.sizes),
					DEC_BASE, tmp);
	len = ft_strlen(tmp);
	if (len == 1 && *tmp == '0' && spec.precision == 0)
		return (ft_zerostr());
	output = (char *)malloc(1 + ((spec.precision > len) ?
								spec.precision : len));
	if (!output)
		return (NULL + (errno = ENOMEM) * 0);
	ft_memcpy(output, tmp, len + 1);
	zero_count = spec.precision - len;
	if (spec.precision != NOT_DETERM && zero_count > 0)
	{
		ft_memmove(output + zero_count, output, len + 1);
		ft_strset(output, '0', zero_count);
	}
	return (output);
}
