/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:27:53 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/24 20:51:06 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <errno.h>
#include <stdlib.h>

char					*ft_zerostr(void)
{
	char *str;

	str = (char *)malloc(1);
	if (!str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	str[0] = '\0';
	return (str);
}
