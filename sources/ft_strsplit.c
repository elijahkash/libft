/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:10:27 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:28:15 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>
#include <ft_memory_manager.h>

static void	*destroy(char **start_destr, char **end_destr)
{
	char	**iter;

	iter = start_destr;
	while (iter < end_destr)
	{
		ft_free(*iter);
		iter++;
	}
	ft_free(start_destr);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	temp_str[ft_findlwordlc(s, c) + 1];
	char	**result;
	int		is_word;
	char	**current_word;

	if (!(result = (char **)ft_malloc(sizeof(char *) * (ft_ccwords(s, c) + 1))))
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
