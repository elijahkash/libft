/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

#include "libft.h"

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
