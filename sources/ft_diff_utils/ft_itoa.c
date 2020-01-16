/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:45:47 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:01 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_memory_manager.h>

static int	ft_itoa_strlen(int n)
{
	int		len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	long long int	tmp;
	int				len;
	char			*str;

	tmp = n;
	len = ft_itoa_strlen(n);
	if (!(str = (char *)ft_malloc(len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		*str = '0';
	if (n < 0)
	{
		*str = '-';
		tmp *= -1;
	}
	while (tmp != 0)
	{
		str[len--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}
