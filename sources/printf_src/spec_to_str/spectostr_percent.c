/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:41 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:45:44 by mtrisha          ###   ########.fr       */
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
