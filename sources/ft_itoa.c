/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:45:47 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/06 20:09:05 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

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
	if (!(str = (char *)malloc(len + 1)))
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
