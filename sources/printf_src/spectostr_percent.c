/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:41 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 17:08:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

#include <ft_printf_spec.h>
#include <libft.h>

char	*spectostr_percent(t_specifications_def spec, va_list argptr)
{
	char *output;

	output = (char *)malloc(2);
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
	output[1] = '\0';
	output[0] = '%';
	spec.spec = argptr ? spec.spec : 0;
	return (output);
}
