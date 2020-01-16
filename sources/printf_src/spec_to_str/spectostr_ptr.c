/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:15:50 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:57 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <prf_get_item_by_size.h>
#include <libft.h>

char	*spectostr_ptr(t_specifications_def spec, va_list argptr)
{
	char *output;
	char tmp[65];

	ft_getunbr_base((unsigned long long)va_arg(argptr, void *),
												LOW_HEX_BASE, tmp);
	output = (char *)ft_malloc(ft_strlen(tmp) + 3);
	if (!output)
		return (NULL);
	output[0] = '0';
	output[1] = 'x';
	ft_memcpy(output + 2, tmp, ft_strlen(tmp) + 1);
	spec.spec = argptr ? spec.spec : 0;
	return (output);
}
