/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:32 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 17:54:59 by mtrisha          ###   ########.fr       */
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

char							ft_check_opt(char *line, char *base)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(base, line[i]))
			return (line[i]);
		i++;
	}
	return (0);
}

t_options						ft_get_opt_bit(const char c)
{
	t_options opt;

	opt = (c >= 'a') ? (1LLU << (c - 'a')) : (1LLU << (c - 'A' + 32));
	return (opt);
}

t_options						ft_get_options(const char *line)
{
	t_options opt;

	opt = 0;
	if (*line == '-')
		line++;
	while (*line)
		opt |= ft_get_opt_bit(*line++);
	return (opt);
}
