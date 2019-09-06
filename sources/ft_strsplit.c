/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:10:27 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/06 20:09:05 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

static void	*destroy(char **start_destr, char **end_destr)
{
	char	**iter;

	iter = start_destr;
	while (iter < end_destr)
	{
		free(*iter);
		iter++;
	}
	free(start_destr);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	temp_str[ft_findlwordlc(s, c) + 1];
	char	**result;
	int		is_word;
	char	**current_word;

	if (!(result = (char **)malloc(sizeof(char *) * (ft_ccwords(s, c) + 1))))
		return (NULL);
	is_word = 0;
	current_word = result;
	while ((*s) || is_word)
	{
		if (is_word && (*s == c || !(*s)))
		{
			temp_str[is_word] = 0;
			*current_word = ft_strdup(temp_str);
			if (!*(current_word++))
				return (destroy(result, --current_word));
			is_word = 0;
		}
		if (*s != c && *s)
			temp_str[is_word++] = *s;
		s = (*s) ? s + 1 : s;
	}
	*current_word = 0;
	return (result);
}
