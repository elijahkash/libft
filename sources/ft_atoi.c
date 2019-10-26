/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:12:43 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/26 19:19:45 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
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

long long int	ft_atoi_l(const char *str)
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
