/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:01:32 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 16:47:00 by mtrisha          ###   ########.fr       */
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
