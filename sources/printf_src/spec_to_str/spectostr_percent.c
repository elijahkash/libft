/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:41 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:57:56 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include <libft.h>

char	*spectostr_percent(t_specifications_def spec, va_list argptr)
{
	char *output;

	output = (char *)ft_malloc(2);
	if (!output)
		return (NULL);
	output[1] = '\0';
	output[0] = '%';
	spec.spec = argptr ? spec.spec : 0;
	return (output);
}
