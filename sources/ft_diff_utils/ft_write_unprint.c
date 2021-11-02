/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_diff_utils.h"

#include "ft_libc.h"

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
