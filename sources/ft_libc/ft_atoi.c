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

#include "ft_libc.h"

#ifdef USE_LIBC

# include <stdlib.h>

inline int				ft_atoi(const char *str)
{
	return (atoi(str));
}

inline long long int	ft_atoi_l(const char *str)
{
	return (atoll(str));
}

#else

int						ft_atoi(const char *str)
{
	int			number;
	size_t		i;
	short int	sign;

	sign = 1;
	i = 0;
	number = 0;
	while (ft_isws(str[i]) || str[i] == '\v' || str[i] == '\f'
											|| str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - 48;
	number *= sign;
	return (number);
}

long long int			ft_atoi_l(const char *str)
{
	long long int	number;
	size_t			i;
	short int		sign;

	sign = 1;
	i = 0;
	number = 0;
	while (ft_isws(str[i]) || str[i] == '\v' || str[i] == '\f'
											|| str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - 48;
	number *= sign;
	return (number);
}

#endif
