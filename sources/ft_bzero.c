/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:13:17 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 12:28:20 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#ifdef TURBO_MOD

void	ft_bzero(void *s, size_t n)
{
	bzero(s, n);
}

#else

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

#endif
