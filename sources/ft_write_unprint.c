/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:36:33 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/20 14:42:39 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <unistd.h>

int		ft_write_unprint(int fd, char *str, size_t len)
{
	size_t ret;

	ret = 0;
	while (len--)
	{
		if (ft_isprint(str[len]))
			ret += write(fd, str + len, 1);
		else
			ret += write(fd, "\e[41m \e[0m", 10);
	}
	return (ret);
}
