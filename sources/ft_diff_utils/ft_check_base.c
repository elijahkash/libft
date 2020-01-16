/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:23:57 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:52 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

int				check_base(char *base)
{
	int i;
	int j;
	int len;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i;
		while (++j < len)
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}
