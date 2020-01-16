/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:11:37 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:58:14 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_error.h>

#include <libft.h>

#include <stdlib.h>
#include <unistd.h>

void	ft_error_exit(const char *msg, int exit_code)
{
	ft_force_buff();
	write(FD_STDERR, msg, ft_strlen(msg));
	exit(exit_code);
}

void	ft_error_free_exit(const char *msg, int exit_code)
{
	ft_force_buff();
	ft_memman_clean();
	write(FD_STDERR, msg, ft_strlen(msg));
	exit(exit_code);
}

void	ft_error_print(const char *msg)
{
	ft_force_buff_fd(FD_STDERR);
	write(FD_STDERR, msg, ft_strlen(msg));
}
