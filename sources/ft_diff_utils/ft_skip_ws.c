/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:43:45 by Kashnitskiy       #+#    #+#             */
/*   Updated: 2020/01/30 15:45:22 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <ft_libc.h>

const char		*ft_skip_ws(const char *str)
{
	while (ft_isws(*str))
		str++;
	return (str);
}
