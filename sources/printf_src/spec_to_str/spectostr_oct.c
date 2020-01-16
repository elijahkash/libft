/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:45:04 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:55 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <prf_get_item_by_size.h>
#include <libft.h>

char	*spectostr_oct(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	tmp[130];
	int		len;
	int		zero_count;

	ft_getunbr_base(get_udec_item_by_size(argptr, spec.sizes),
					OCT_BASE, tmp);
	len = ft_strlen(tmp);
	if (len == 1 && *tmp == '0' && spec.precision == 0)
		return (ft_zerostr());
	output = (char *)ft_malloc(60 + ((spec.precision > len) ?
								spec.precision : len));
	if (!output)
		return (NULL);
	ft_memcpy(output, tmp, len + 1);
	zero_count = spec.precision - len;
	if (spec.precision != NOT_DETERM && zero_count > 0)
	{
		ft_memmove(output + zero_count, output, len + 1);
		ft_strset(output, '0', zero_count);
	}
	return (output);
}
