/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:45:47 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/04 18:11:31 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		tmp;
	int		len;

	tmp = n;
	len = (n <= 0) ? 1 : 0;
	while (tmp != 0)
	{
		++len;
		tmp /= 10;
	}
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
