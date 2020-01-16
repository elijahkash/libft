/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:27:53 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:31 by Kashnitskiy      ###   ########.fr       */
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
