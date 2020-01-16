/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:59:42 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:56:15 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_diff_utils.h>

#include <libft.h>

#include <unistd.h>

void	ft_putstr(char const *s)
{
	write(FD_STDOUT, s, ft_strlen(s));
	return ;
}
