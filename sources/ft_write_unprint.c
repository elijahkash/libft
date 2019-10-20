/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:36:33 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/20 16:10:40 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
