/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_sdec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:32:16 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/24 19:10:14 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

#include <ft_printf_spec.h>
#include <libft.h>
#include <utils.h>

char	*spectostr_sdec(t_specifications_def spec, va_list argptr)
{
	char 	*output;
	char 	tmp[65];
	int		len;
	int		sign;

	ft_getsnbr_base(get_dec_item_by_size(argptr, spec.sizes), DEC_BASE, tmp);
	len = ft_strlen(tmp);
	sign = ((*tmp == '-') ? 1 : 0);
	if (spec.precision > len - sign)
		output = (char *)malloc(spec.precision + 1 + sign);
	else
		output = (char *)malloc(len + 1);
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
	strset(output, '0', (spec.precision != NOT_DETERM) ? spec.precision : 0);
	if (spec.precision > len - sign)
		ft_memcpy(output + spec.precision - len + sign,
					tmp + sign, len + 1 - sign);
	else
		ft_memcpy(output, tmp, len + 1);
	if (tmp[0] == '-')
		output[0] = '-';
	return (output);
}
