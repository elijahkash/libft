/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_sdec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:32:16 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/24 17:47:55 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

#include <ft_printf_spec.h>
#include <libft.h>
#include <utils.h>

char	*spectostr_sdec(t_specifications_def spec, va_list argptr)
{
	char *output;
	char tmp[65];

	//ft_bzero(tmp, 65);
	ft_getsnbr_base(get_dec_item_by_size(argptr, spec.sizes), DEC_BASE, tmp);
	output = (char *)malloc(ft_strlen(tmp) + 1);
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(output, tmp, ft_strlen(tmp) + 1);
	//TODO: precision
	return (output);
}
