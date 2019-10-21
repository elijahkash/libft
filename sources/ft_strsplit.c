/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:10:27 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/21 16:14:23 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

t_str		**ft_tstrsplit(t_str s, int (*f)(char))
{
	char	temp_str[ft_findlwordlf(s, f) + 1];
	t_str	temp_tstr;
	t_str	**result;
	t_str	**current_word;
	size_t	i;

	i = 0;
	temp_tstr.str = temp_str;
	temp_tstr.len = 0;
	result = (t_str **)ft_malloc(sizeof(t_str *) * (ft_cfwords(s, f) + 1));
	current_word = result;
	while (i < s.len || temp_tstr.len)
	{
		if (temp_tstr.len && (f(s.str[i]) || i == s.len))
		{
			*current_word++ = ft_tstrdup(temp_tstr);
			temp_tstr.len = 0;
		}
		if (!f(s.str[i]) && i < s.len)
			temp_str[temp_tstr.len++] = s.str[i];
		i = i < s.len ? i + 1 : i;
	}
	*current_word = NULL;
	return (result);
}
