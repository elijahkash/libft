/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:41:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 13:51:19 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#include <libft.h>

const char	*skip_digits(const char *format)
{
	while (ft_isdigit(*format))
		format++;
	return (format);
}
