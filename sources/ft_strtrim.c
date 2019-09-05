/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:01:02 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/05 17:01:59 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = ft_strlen(s) - 1;
	while (ft_isws(s[start]))
		start++;
	while (ft_isws(s[end]))
		end = (!end) ? 0 : end - 1;
	len = (start < end) ? end - start : 0;
	str = ft_strnew(len);
	if (!str)
		return(NULL);
	ft_memcpy((void *)str, &(s[start]), len);
	return (str);
}
