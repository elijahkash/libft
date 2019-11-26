/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:59:42 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:30:05 by mtrisha          ###   ########.fr       */
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
