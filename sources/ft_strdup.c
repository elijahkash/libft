/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:43:32 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/21 12:29:12 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char *str;

	str = ft_strnew(ft_strlen(s1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, ft_strlen(s1));
	return (str);
}

t_str	ft_tstrdup(t_str s)
{
	t_str	res;

	res.str = ft_strnew(s.len);
	res.len = s.len;
	ft_memcpy(res.str, s.str, s.len);
	return (res);
}
