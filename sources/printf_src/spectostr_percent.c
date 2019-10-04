/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:41 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 22:32:23 by mtrisha          ###   ########.fr       */
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
