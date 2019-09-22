/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:20:48 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 12:52:26 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_pow(int n, int pow)
{
	int i;
	int result;

	i = 1;
	result = n;
	if (pow == 0)
		return (1);
	while (i++ < pow)
		result *= n;
	return (result);
}
