/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:41 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 13:41:20 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <spectostr_funcs.h>

#include <ft_printf_spec.h>
#include <libft.h>

char	*spectostr_percent(t_specifications_def spec, va_list argptr)
{
	spec.spec = argptr ? spec.spec : 0;
	ft_putchar('%');
	return (1);
}
