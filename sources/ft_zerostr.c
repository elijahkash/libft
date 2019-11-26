/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:27:53 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:08:45 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_memory_manager.h>

char		*ft_zerostr(void)
{
	char *str;

	str = (char *)ft_malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
