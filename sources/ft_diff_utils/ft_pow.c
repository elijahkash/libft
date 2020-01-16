/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:20:48 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:03 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

int		ft_pow(int n, int pow)
{
	int result;

	result = n;
	if (pow-- == 0)
		return (1);
	while (pow--)
		result *= n;
	return (result);
}
