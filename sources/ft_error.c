/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:11:37 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 17:03:15 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_error.h>

#include <libft.h>

#include <stdlib.h>
#include <unistd.h>

void	ft_error_exit(const char *msg, int exit_code)
{
	write(FD_STDERR, msg, ft_strlen(msg));
	exit(exit_code);
}

void	ft_error_free_exit(const char *msg, int exit_code)
{
	ft_gc_clean();
	ft_error_exit(msg, exit_code);
}

void	ft_error_print(const char *msg)
{
	write(FD_STDERR, msg, ft_strlen(msg));
}
