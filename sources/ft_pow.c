/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:20:48 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:32:16 by mtrisha          ###   ########.fr       */
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
