/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:36:33 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:37:06 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

#include <unistd.h>

int		ft_write_unprint(int fd, char *str, size_t len)
{
	size_t ret;
	size_t i;

	ret = 0;
	i = 0;
	while (len--)
	{
		if (ft_isprint(str[i]))
			ret += write(fd, str + i, 1);
		else
			ret += write(fd, "\e[41m \e[0m", 10);
		i++;
	}
	return (ret);
}
