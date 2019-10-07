/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:32 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 15:40:03 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_options.h>

#include <libft.h>

int								ft_is_option(const char *line)
{
	if (*line == '-')
		return (1);
	return (0);
}

int								ft_is_validopt(char *line)
{
	if (*line++ != '-')
		return (0);
	while (*line)
	{
		if (*line < 'A' || *line > 'z' || (*line > 'Z' && *line < 'a'))
			return (0);
		line++;
	}
	return (1);
}

t_options						ft_get_options(const char *line)
{
	t_options opt;

	opt = 0;
	if (*line == '-')
		line++;
	while (*line)
	{
		opt |= (*line >= 'a') ? (1LLU << (*line - 'a')) :
								(1LLU << (*line - 'A' + 32));
		line++;
	}
	return (opt);
}
